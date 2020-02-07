#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

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
    snprintf(program, sizeof(program), "exp = %s; print(exp)", buffer);
    execlp("python3", "python3", "-c", program, NULL);
    perror("exec");
    exit(1);
}