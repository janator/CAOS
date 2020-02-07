#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *file_name = argv[1];
    char *pattern = argv[2];
    int fd = open(file_name, O_RDONLY);
    struct stat st;
    fstat(fd, &st);
    if (st.st_size == 0) {  close(fd); return 0;}
    char *contents = mmap(NULL,
                          st.st_size,
                          PROT_READ,
                          MAP_PRIVATE,
                          fd,
                          0);
    char* entry = contents;
    size_t len = st.st_size;
    while (NULL != (entry=memmem(entry, len, pattern, strlen(pattern)))) {
        size_t diff = entry - contents;
        len = st.st_size - diff - 1;
        printf("%lu ", diff);
        entry++;
    }
    printf("\n");
    munmap(contents, st.st_size);
    close(fd);
    return 0;
}