#include <sys/mman.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
struct Item {
    int value;
    uint32_t next_pointer;
};
int main(int argc, char* argv[]) {
    char *file_name = argv[1];
    int fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return 0;
    struct stat st;
    fstat(fd, &st);
    if (!st.st_size) {
        close(fd);
        return 0;
    }
    char *contents = mmap(NULL,
            st.st_size,
            PROT_READ,
            MAP_SHARED,
            fd,
            0);
    struct Item *it = (struct Item*) malloc(sizeof(struct Item));
    memcpy(it, contents, sizeof(struct Item));
    printf("%d\n", it->value);
    while (it->next_pointer) {
        memcpy(it, contents + it->next_pointer, sizeof(struct Item));
        printf("%d\n", it->value);
    }
    munmap(contents, st.st_size);
    close(fd);
    return 0;
}