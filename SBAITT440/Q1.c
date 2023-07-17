#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void childInterrupt(int sig) {
    printf("Ini Gangguan\n");
    exit(0);
}

int main() {
    pid_t c1, c2, c3;

    c1 = fork();

    if (c1 == 0) {
       
        signal(SIGINT, childInterrupt);
        while (1) {
            printf("Jangan Tiru\n");
            sleep(1);
        }
    } else {
        c2 = fork();
        if (c2 == 0) {
            
            signal(SIGINT, childInterrupt);
            while (1) {
                printf("Jangan Ganggu\n");
                sleep(1);
            }
        } else {
            c3 = fork();
            if (c3 == 0) {
                
                signal(SIGINT, childInterrupt);
                while (1) {
                    printf("Buat Apa tu?\n");
                    sleep(1);
                }
            } else {
               
                printf("This is your parent process\n");
                sleep(5);
            }
        }
    }

    return 0;
}

