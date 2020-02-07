#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long n = strtol(argv[1], NULL, 10);
    pid_t pid;
    for (long i = 1; i <= n; ++i) {
        if (0 == (pid = fork())) {
            if (i < n) {
                printf("%ld ", i);
            } else {
                printf("%ld\n", i);
            }
            exit(0);
        }
        int status = 0;
        waitpid(pid, &status, 0);
    }
    return 0;
}