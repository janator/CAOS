#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int fds_pair1[2];
    int fds_pair2[2];
    pipe(fds_pair1);
    pipe(fds_pair2);
    pid_t pid = fork();
    if (!pid) {
        dup2(fds_pair2[1], 1);
        close(fds_pair2[0]);
        close(fds_pair2[1]);
        execlp(argv[1], argv[1], NULL);
    }
    close(fds_pair1[0]);
    close(fds_pair1[1]);
    waitpid(pid, 0, 0);
    fds_pair1[0] = fds_pair2[0];
    fds_pair1[1] = fds_pair2[1];
    pipe(fds_pair2);
    for (int i = 2; i < argc; ++i) {
        pid = fork();
        if (!pid) {
            dup2(fds_pair1[0], 0);
            close(fds_pair1[0]);
            close(fds_pair1[1]);
            if (i != argc - 1) {
                dup2(fds_pair2[1], 1);
                close(fds_pair2[0]);
                close(fds_pair2[1]);
            }
            execlp(argv[i], argv[i], NULL);
        }
        close(fds_pair1[0]);
        close(fds_pair1[1]);
        waitpid(pid, 0, 0);
        if (i == argc - 1)
            break;
        fds_pair1[0] = fds_pair2[0];
        fds_pair1[1] = fds_pair2[1];
        pipe(fds_pair2);
    }
    return 0;
}