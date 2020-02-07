#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>

void print_rwx(int a) {
    for (int i = 0; i < 9; i += 1) {
        if (a & (1 << (8 - i))) {
            if (i % 3 == 0) {
                printf("r");
            }
            else if (i % 3 == 1) {
                printf("w");
            }
            else {
                printf("x");
            }
        }
        else {
            printf("-");
        }
    }
}

void print_info(struct stat *st, char * name) {
    if (S_ISBLK(st -> st_mode)){
        printf("b");
    }
    else if (S_ISCHR(st -> st_mode)) {
        printf("c");
    }
    else if (S_ISDIR(st -> st_mode)) {
        printf("d");
    }
    else if (S_ISFIFO(st -> st_mode)) {
        printf("p");
    }
    else if (S_ISLNK(st -> st_mode)) {
        printf("l");
    }
    else if (S_ISSOCK(st -> st_mode)) {
        printf("s");
    }
    else if (S_ISREG(st -> st_mode)) {
        printf("-");
    }

    print_rwx(st -> st_mode % 512);

    printf(" %ld ", st -> st_nlink);

    struct passwd *user = getpwuid(st -> st_uid);
    if (user == NULL) {
        printf("%d ", st -> st_uid);
    }
    else {
        printf("%s ", user -> pw_name);
    }

    struct group *group = getgrgid(st -> st_gid);
    if (group == NULL) {
        printf("%d ", st -> st_gid);
    }
    else {
        printf("%s ", group -> gr_name);
    }

    printf("%ld ", st -> st_size);
}


int main(int argc, char *argv[]) {
    struct stat st;
    struct dirent *entry;

    if (lstat(argv[1], &st) == -1) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(1);
    }

    if (!S_ISDIR(st.st_mode)) {
        print_info(&st, argv[1]);
        char *name = argv[1];
        if (S_ISLNK(st.st_mode)) {
            char *res = malloc(PATH_MAX * sizeof(char));
            ssize_t ret;
            ret = readlink(argv[1], res, PATH_MAX);
            if (ret == -1) {
                fprintf(stderr, "%s\n", strerror(errno));
                exit(1);
            }
            *(res + ret) = '\0';
            printf("%s -> %s\n", name, res);
            free(res);
        }
        else {
            printf("%s\n", name);
        }
        return 0;
    }

    int dirfd = open(argv[1], O_RDONLY | O_DIRECTORY);
    if (dirfd == -1) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(1);
    }

    DIR *current_dir = fdopendir(dirfd);
    if (current_dir == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(1);
    }

    while (entry = readdir(current_dir)) {
        if (!strncmp(entry -> d_name, ".", 1))
            continue;
        if (fstatat(dirfd, entry -> d_name, &st, AT_SYMLINK_NOFOLLOW) == -1) {
            fprintf(stderr, "%s\n", strerror(errno));
            exit(1);
        }
        print_info(&st, entry -> d_name);
        if (S_ISLNK(st.st_mode)) {
            char *res = malloc(PATH_MAX * sizeof(char));
            ssize_t ret = readlinkat(dirfd, entry -> d_name, res, PATH_MAX);
            if (ret == -1) {
                fprintf(stderr, "%s\n", strerror(errno));
                exit(1);
            }
            *(res + ret) = '\0';
            printf("%s -> %s\n", entry -> d_name, res);
            free(res);
        }
        else {
            printf("%s\n", entry -> d_name);
        }
    }

    close(dirfd);

    return 0;
}