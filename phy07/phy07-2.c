#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <fcntl.h>

void countSize(char *catalog, size_t *size) {
    int dirfd = open(catalog, O_RDONLY | O_DIRECTORY);
    if (dirfd == -1)
        return;
    DIR *dir = fdopendir(dirfd);
    struct dirent *entry;
    struct stat st;
    while ((entry=readdir(dir))) {
        fstatat(dirfd, entry->d_name, &st, 0);
        if (S_ISREG(st.st_mode)) {
            *size += st.st_size;
        }
        if (S_ISDIR(st.st_mode)) {
            char name[NAME_MAX];
            strcpy(name, entry->d_name);
            if (strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
                char path[PATH_MAX];
                snprintf(path, PATH_MAX, "%s/%s", catalog, entry->d_name);
                countSize(path, size);
            }
        }
    }
    closedir(dir);
}
int main(int argc, char* argv[]) {
    size_t size = 0;
    countSize(argv[1], &size);
    printf("%"PRId64"\n", size);
    return 0;
}