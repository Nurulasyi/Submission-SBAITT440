#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024
#define TCP_SERVER_IP "127.0.0.1"
#define TCP_SERVER_PORT 6014

int main() {
    int sfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr;

    
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(TCP_SERVER_IP);
    server_addr.sin_port = htons(TCP_SERVER_PORT);
    
    if (connect(sfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Can't connect");
        exit(EXIT_FAILURE);
    }
    
    ssize_t recv_len = recv(sfd, buffer, sizeof(buffer), 0);
    if (recv_len < 0) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    buffer[recv_len] = '\0';
    int random_number = atoi(buffer);

    printf("Random  number: %d\n", random_number);
   
    close(sfd);

    return 0;
}

