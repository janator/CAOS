#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    char *program = argv[1];
    int fds_pair[2];
    pipe(fds_pair);
    pid_t pid = fork();
    if (!pid) {
        dup2(fds_pair[1], STDERR_FILENO);
        close(fds_pair[1]);
        execlp("gcc", "gcc", program, NULL);
    }
        close(fds_pair[1]);
        int count_errors = 0;
        int count_warnings = 0;
        char buffer[4096];
        FILE *fd = fdopen(fds_pair[0], "r");
        int line = 0, pos = 0;
        int prev_err_line = -1;
        int prev_war_line = -1;
        char* search = malloc(strlen(program) + 8);
        strcpy(search, program);
        strcat(search, ":%d:%d:");
        while (fscanf(fd, "%s", buffer) != EOF) {
            if (sscanf(buffer, search, &line, &pos) == 2) {
                fscanf(fd, "%s", buffer);
                if (!strncmp(buffer, "error", 5)) {
                    if (line != prev_err_line) {
                        ++count_errors;
                        prev_err_line = line;
                    }
                }
                if (!strncmp(buffer, "warning", 7)) {
                    if (line != prev_war_line) {
                        ++count_warnings;
                        prev_war_line = line;
                    }
                }
            }
        }
        waitpid(pid, 0, 0);
        printf("%d %d", count_errors, count_warnings);
        fclose(fd);
        free(search);
    return 0;
}