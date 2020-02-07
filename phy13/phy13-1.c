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
#include <sys/epoll.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

volatile sig_atomic_t work = 1;

void handler(int sig) {
    work = 0;
}

static void make_non_blocking(int fd) {
    int flags = fcntl(fd, F_GETFD);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

static void create_event_data(int epoll_fd, int fd) {
    make_non_blocking(fd);
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event);
}
int main(int argc, char* argv[]) {

    typedef struct sigaction Sigaction;

    Sigaction act = {
            .sa_handler = handler,
            .sa_flags = SA_RESTART,
    };
    sigaction(SIGTERM, &act, NULL);
    sigaction(SIGINT, &act, NULL);
    sigset_t set;
    sigfillset(&set);
    sigdelset(&set, SIGTERM);
    sigdelset(&set, SIGINT);
    sigprocmask(SIG_SETMASK, &set, NULL);

    struct sockaddr_in addr;
    bzero((void*)(&addr), sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(strtol(argv[1], NULL, 10));
    inet_aton("127.0.0.1", &addr.sin_addr);
    int server_sd = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(server_sd, (struct sockaddr*) &addr, sizeof(addr)) != 0) {
        perror("error bind");
        close(server_sd);
        exit(1);
    }
    if (listen(server_sd, 128) != 0) {
        perror("error listen");
        close(server_sd);
        exit(2);
    }
    int epoll_fd = epoll_create1(0);
    struct epoll_event waiting[10000];
    create_event_data(epoll_fd, server_sd);
    while (work) {
        int n = epoll_wait(epoll_fd, waiting, sizeof(waiting), -1);
        for (int i = 0; i < n; ++i) {
            if (waiting[i].data.fd != server_sd) {
                char buffer[4096];
                int now_read = 0;
                while ((now_read = read(waiting[i].data.fd, buffer, sizeof(buffer))) > 0) {
                    for (int j = 0; j < now_read; ++j) {
                        buffer[j] = toupper(buffer[j]);
                    }
                    write(waiting[i].data.fd, buffer, now_read);
                }
            } else {
                unsigned int size = sizeof(addr);
                int sd = accept(server_sd, (struct sockaddr*) &addr, &size);
                if (sd == -1)
                    break;
                create_event_data(epoll_fd, sd);
            }
        }
    }
    close(server_sd);

    return 0;
}