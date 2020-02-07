#include <sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdio.h>
#include <inttypes.h>

struct Item {
    int value;
    uint32_t next_pointer;
};

int main(int argc, char* argv[]) {
    struct Item a;
    int in = open(argv[1], O_RDONLY);
    ssize_t r = read(in, &a, sizeof(a));
    if (r == 0) {
        goto finally;
    }
    printf("%d ", a.value);
    while (a.next_pointer) {
        lseek(in, a.next_pointer, SEEK_SET);
        read(in, &a, sizeof(a));
        printf("%d ", a.value);
    }
  finally:
    close(in);
    return 0;
}