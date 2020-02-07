#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char* cmd1 = argv[1];
    char* cmd2 = argv[2];

    int pair[2];
    pipe(pair);
    pid_t pid = fork();
    if (!pid) {
        dup2(pair[1], 1);
        close(pair[1]);
        execlp(cmd1, cmd1, NULL);
    } else {
        close(pair[1]);
        dup2(pair[0], 0);
        close(pair[0]);
        waitpid(pid, 0, 0);
        execlp(cmd2, cmd1, NULL);
    }
    return 0;
}