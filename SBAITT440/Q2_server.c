#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 1024
#define TCP_PORT 6014

int main() {
    int sfd, client_sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(TCP_PORT);
    
    if (bind(sfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Can't Bind");
        exit(EXIT_FAILURE);
    }
    
    if (listen(sfd, 1) < 0) {
        perror("Can't listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for a client...\n");
    while (1) {
        client_len = sizeof(client_addr);
      
        client_sockfd = accept(sfd, (struct sockaddr*)&client_addr, &client_len);
        if (client_sockfd < 0) {
            perror("Can't accept");
            exit(EXIT_FAILURE);
        }
       
        int random_number = rand() % 80000 + 50000;
        
        sprintf(buffer, "%d", random_number);
   
        ssize_t send_len = send(client_sockfd, buffer, strlen(buffer), 0);
        if (send_len < 0) {
            perror("Can't Send");
            exit(EXIT_FAILURE);
        }
        close(client_sockfd);
    }
    close(sfd);

    return 0;
}

