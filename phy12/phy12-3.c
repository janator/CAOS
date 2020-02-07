#include <stdio.h>
#include <signal.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <wait.h>


volatile sig_atomic_t work = 1;

void handler(int sig) {
    work = 0;
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("argc");
        return 1;
    }

    typedef struct sigaction Sigaction;

    Sigaction act = {
            .sa_handler = handler,
            .sa_flags = SA_RESTART,
    };

    sigset_t set;
    sigfillset(&set);
    sigaction(SIGTERM, &act, NULL);
    sigdelset(&set, SIGTERM);
    sigaction(SIGINT, &act, NULL);
    sigdelset(&set, SIGINT);
    sigprocmask(SIG_SETMASK, &set, NULL);

    struct sockaddr_in addr;
    bzero((void*)(&addr), sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(strtol(argv[1], NULL, 10));
    inet_aton("127.0.0.1", &addr.sin_addr);

    int server_sd = socket(AF_INET, SOCK_STREAM, 0);

    if(bind(server_sd, (struct sockaddr*)&addr, sizeof(addr)) != 0) {
        perror("error bind");
        close(server_sd);
        return 1;
    }

    if(listen(server_sd, 128) != 0) {
        perror("error listen" );
        close(server_sd);
        return 2;
    }

    int dir_fd = open(argv[2], O_RDONLY);

    if (dir_fd < 0) {
        perror("open dir");
        close(server_sd);
        return 3;
    }

    while(work) {
        unsigned int size_of_addr = sizeof(addr);

        act.sa_flags = 0;
        sigaction(SIGTERM, &act, NULL);
        sigaction(SIGINT, &act, NULL);

        int sd = accept(server_sd, (struct sockaddr*)&addr, &size_of_addr);

        act.sa_flags = SA_RESTART;
        sigaction(SIGTERM, &act, NULL);
        sigaction(SIGINT, &act, NULL);


        if (sd == -1) {
            break;
        }

        char name_of_file[0x1000];

        int clone_sd = dup(sd);
        FILE *stream = fdopen(clone_sd, "r");
        fscanf(stream, "GET %s HTTP/1.1", name_of_file);
        fclose(stream);

        if (faccessat(dir_fd, name_of_file, 0, 0) != 0) {
            write(sd, "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n", strlen("HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n"));
            close(sd);
            continue;
        }

        if (faccessat(dir_fd, name_of_file, R_OK, 0) != 0) {
            write(sd, "HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\n\r\n", strlen("HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\n\r\n"));
            close(sd);
            continue;
        }

        write(sd, "HTTP/1.1 200 OK\r\n", strlen("HTTP/1.1 200 OK\r\n"));

        int file = openat(dir_fd, name_of_file, O_RDONLY);
        if (faccessat(dir_fd, name_of_file, X_OK, 0) == 0) {
            char full_file[strlen(argv[2]) + strlen(name_of_file) + 2];
            strcpy(full_file, argv[2]);
            if (full_file[strlen(full_file) - 1] != '/') {
                strcat(full_file, "/");
            }
            strcat(full_file, name_of_file);

            pid_t pid = fork();

            if (pid == 0) {
                dup2(sd, 1);
                execl(full_file, name_of_file, NULL);
                perror("fork");
                fflush(stdout);
                return 1;
            }

            waitpid(pid, 0, 0);

        } else {
            struct stat st;
            fstat(file, &st);

            char size_print[0x1000 + 1];
            snprintf(size_print, 0x1000, "Content-Length: %ld\r\n\r\n", st.st_size);
            write(sd, size_print, strlen(size_print));

            char buff[0x1000];

            int now_read = 0;
            while ((now_read = read(file, buff, 0x4096)) > 0) {
                write(sd, buff, now_read);
            }
        }
        close(sd);
    }

    close(server_sd);

    return 0;
}