#define _FILE_OFFSET_BITS 64
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

int main() {
    struct stat st;
    char file[PATH_MAX + 1];
    char new_file[PATH_MAX + 1];
    char new_path[PATH_MAX + 1];
    char *end;
    while (fgets(file, sizeof(file), stdin)) {
        end = memchr(file, '\n', sizeof(file));
        if (end)
            *end = '\0';
        if (lstat(file, &st) == 0 && S_ISLNK(st.st_mode)) {
            realpath(file, new_file);
            puts(new_file);
        } else if (lstat(file, &st) == 0 && S_ISREG(st.st_mode)) {
            realpath(file, new_file);
            char* dirc = strdup(new_file);
            char* basec = strdup(new_file);
            char* dir = dirname(dirc);
            char* base = basename(basec);
            strcpy(new_path, dir);
            strcat(new_path, "/link_to_");
            strcat(new_path, base);
            symlink(file, new_path);
        }
    }
    return 0;
}