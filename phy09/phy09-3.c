#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char buffer[5000];
    char program[5000];
    fgets(buffer, sizeof(buffer), stdin);
    char* slash_n_pos = memchr(buffer, '\n', sizeof(buffer));
    if (slash_n_pos) {
        *slash_n_pos = '\0';
    }
    if (0==strlen(buffer)) {
        return 0;
    }
    int fd = open("vika.c", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    snprintf(program, sizeof(program), "#include <stdio.h>\n int main() { int value = (%s); printf(\"%%d\", value); return 0; }", buffer);
    write(fd, program, strlen(program));
    close(fd);
    pid_t pid = fork();
    if (!pid) {
        execlp("gcc", "gcc",  "vika.c", "-o", "vika", NULL);
        exit(0);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
    execlp("./vika", "./vika", NULL);
    perror("exec");
    exit(1);
}