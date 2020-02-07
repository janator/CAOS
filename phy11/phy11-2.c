#include <sys/signalfd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void TransferLine(FILE *from) {
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    fgets(buffer, sizeof(buffer), from);
    fputs(buffer, stdout);
    fflush(stdout);
}
int main(int argc, char* argv[]) {
    FILE *file[argc-1];
    for (int i = 1; i < argc; ++i) {
        file[i - 1] = fopen(argv[i], "r");
    }
    sigset_t mask_to_block, mask_to_catch;
    sigfillset(&mask_to_block);
    sigemptyset(&mask_to_catch);
    for (int i = 0; i < argc; ++i) {
        sigaddset(&mask_to_catch, SIGRTMIN + i);
    }
    sigprocmask(SIG_BLOCK, &mask_to_block, NULL);
    int fd = signalfd(-1, &mask_to_block, 0);
    struct signalfd_siginfo si;
    int index;
    while (1) {
        read(fd, &si, sizeof(si));
        index = si.ssi_signo - SIGRTMIN;
        if (!index) {
            break;
        } else {
            TransferLine(file[index - 1]);
        }
    }
    close(fd);
    for (int i = 1; i < argc; ++i) {
        fclose(file[i - 1]);
    }
    return 0;
}