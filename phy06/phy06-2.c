#define _FILE_OFFSET_BITS 64
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char file_name[PATH_MAX];
    uint64_t result = 0;
    struct stat st;
    char *nl;
    while (fgets(file_name, sizeof(file_name), stdin)) {
        nl = memchr(file_name, '\n', sizeof(file_name));
        if (nl) {
            *nl = '\0';
        }
        if (-1 != lstat(file_name, &st)) {
            if (S_ISREG(st.st_mode)) {
                result += st.st_size;
            }
        }
    }
    printf("%"PRId64"\n", result);
    return 0;
}