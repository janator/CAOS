#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
volatile sig_atomic_t  counter = 0;
volatile sig_atomic_t must_exit = 0;

void handle_sigusr1(int signum) {
    ++counter;
}

void handle_sigusr2(int signum) {
    counter *= -1;
}

void handle_sigterm(int signum) {
    must_exit = 1;
}
int main() {

    struct sigaction action_int;
    memset(&action_int, 0, sizeof(action_int));
    action_int.sa_handler = handle_sigusr1;
    action_int.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &action_int, NULL);

    struct sigaction action_int1;
    memset(&action_int1, 0, sizeof(action_int1));
    action_int1.sa_handler = handle_sigusr2;
    action_int1.sa_flags = SA_RESTART;
    sigaction(SIGUSR2, &action_int1, NULL);

    struct sigaction action_term;
    memset(&action_term, 0, sizeof(action_term));
    action_term.sa_handler = handle_sigterm;
    action_term.sa_flags = SA_RESTART;
    sigaction(SIGTERM, &action_term, NULL);

    printf("%d\n", getpid());
    fflush(stdout);
    scanf("%d", &counter);
    while (!must_exit) {
        pause();
        printf("%d ", counter);
        fflush(stdout);
    }

    return 0;
}