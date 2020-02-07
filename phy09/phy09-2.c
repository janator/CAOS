#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid = 0;
    int word_number = 0;
    char word[4097];
    char empty_in = 1;
    int status;
    while (!pid) {
        ++word_number;
        if (scanf("%s", word) != EOF) {
            pid = fork();
            empty_in = 0;
        } else {
            break;
        }
    }
    if (empty_in) {
        printf("%d\n", 0);
    }
    if (pid) {
        waitpid(pid, &status, 0);
        status = WEXITSTATUS(status);
        if (word_number == 1)
            printf("%d\n", status + 1);
        else
            exit(status + 1);
    }
    return 0;
}