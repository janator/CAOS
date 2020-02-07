#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    long port_num = strtol(argv[1], NULL, 10);
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("can't creat socket");
        exit(1);
    }
    struct sockaddr_in dest_addr = {
            .sin_family = AF_INET,
            .sin_addr = inet_addr("127.0.0.1"),
            .sin_port = htons(port_num)
    };
    int num1, num2;
    while (scanf("%d", &num1) > 0) {
        sendto(sock, &num1, sizeof(num1), 0, (const struct sockaddr*) &dest_addr, sizeof(dest_addr));
        recvfrom(sock, &num2, sizeof(num2), 0, NULL, NULL);
        printf("%d\n", num2);
    }
    close(sock);
    return 0;
}