#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

void format(char* pointer, int n, int W) {
    char a = pointer[W];
    sprintf(pointer, "%*d", W, n);
    pointer[W] = a;
}

void write_matrix(int W, int N, int n, int offset, int start, char* text) {
    if (n == 1) {
        format(text + W * (N * offset + offset) + offset, start, W);
    }
    else if (n == 2) {
        format(text + W * (N * offset + offset) + offset, start, W);
        format(text + W * (N * offset + offset + 1) + offset, start + 1, W);
        format(text + W * (N * (offset + 1) + offset + 1) + 1 + offset, start + 2, W);
        format(text + W * (N * (offset + 1) + offset) + 1 + offset, start + 3, W);
    }
    else {
        for (int i = 0; i < n; i++) {
            format(text + W * (N * offset + offset + i) + offset, start + i, W);
        }
        for (int i = 0; i < n - 2; i++) {
            format(text + W * (N * (offset + 1 + i) + offset + n - 1) + 1 + i + offset, start + n + i, W);
        }
        for (int i = 0; i < n; i++) {
            format(text + W * (N * (offset + n - 1) + offset + i) + n - 1 + offset, start + 3 * (n - 1) - i, W);
        }
        for (int i = 0; i < n - 2; i++) {
            format(text + W * (N * (offset + 1 + i) + offset) + 1 + i + offset, start + 4 *(n - 1) - 1 - i, W);
        }
        write_matrix(W, N, n - 2, offset + 1, start + 4 * (n - 1), text);
    }
}

int main(int argc, char* argv[]) {
    FILE* stream = fopen(argv[1], "w+");
    int fd = open(argv[1], O_RDWR);
    int N = strtol(argv[2], NULL, 10);
    int W = strtol(argv[3], NULL, 10);
    lseek(fd, N * N * W + N - 2, SEEK_SET);
    char end = '\0';
    write(fd, &end, 1);
    int file_len = N*N*W + N - 1;
    char* contents = mmap(NULL, file_len, PROT_WRITE, MAP_SHARED, fd, 0);
    for(int i = 0; i < N - 1; ++i) {
        contents[(i + 1) * N * W + i] = '\n';
    }
    write_matrix(W, N, N, 0, 1, contents);
    munmap(contents, file_len);
    fclose(stream);
    return 0;
}