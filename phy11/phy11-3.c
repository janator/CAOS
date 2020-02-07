#include <stdio.h>
#include<signal.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

volatile uint32_t N;
volatile pid_t pid;

void handler_sigrtmin (int signum, siginfo_t* info, void *t) {
    N = info->si_value.sival_int;
    pid = info->si_pid;
}


int main() {
    sigset_t mask_to_block;
    sigfillset(&mask_to_block);
    sigdelset(&mask_to_block, SIGRTMIN);
    sigprocmask(SIG_BLOCK, &mask_to_block, NULL);

    struct sigaction action_sigrtmin;
    memset(&action_sigrtmin, 0, sizeof(action_sigrtmin));
    action_sigrtmin.sa_flags = SA_RESTART | SA_SIGINFO;
    action_sigrtmin.sa_sigaction = handler_sigrtmin;
    sigaction(SIGRTMIN, &action_sigrtmin, NULL);

    while(1) {
        pause();
        if (!N)
            return 0;
        union sigval value;
        memset(&value, 0, sizeof(value));
        value.sival_int = --N;
        sigqueue(pid, SIGRTMIN, value);
    }
    return 0;
}