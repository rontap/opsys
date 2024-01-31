//
// Created by rontap on 16/05/2023.
//
#include "libopsys.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void handler(int signumber) {
    printf("[handler] Signal with number %i has arrived\n", signumber);
}

char pipe_1_loc[20];
char pipe_2_loc[20];


int main(int argc, char **argv) {
    errno = 0;
    sprintf(pipe_1_loc, "/tmp/%d_1", getpid());
    sprintf(pipe_2_loc, "/tmp/%d_2", getpid());
    char str[1024] = "String To Send\0";
    printf("??");
    // 1a: signal
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);

    printf("??");
    // 1b: pipe

    unlink(pipe_1_loc);
    unlink(pipe_2_loc);

    int pipe_fifo_1 = mkfifo(pipe_1_loc, S_IRUSR | S_IWUSR);
    int pipe_fifo_2 = mkfifo(pipe_2_loc, S_IRUSR | S_IWUSR);

    printf("%i %i %i", pipe_fifo_1, pipe_fifo_2, errno);

    int pipe_1 = open(pipe_1_loc, O_WRONLY | O_RDONLY);
    int pipe_2 = open(pipe_2_loc, O_WRONLY) |  O_RDONLY;
    printf("--%i %i %i", pipe_1, pipe_2, errno);

    printf("??");

    pid_t child_1, child_2;

    child_1 = fork();
    if (child_1 > 0) {
        child_2 = fork();
        if (child_2 > 0) {
            // 1a: signal
            printf("->signal\n");
            pause();
            printf("->2signal\n");
            pause();
            printf("->3signal\n");


            printf("%i %i", pipe_1, pipe_2);

            write(pipe_1, str, sizeof(str));
            write(pipe_2, str, sizeof(str));

            close(pipe_1);
            close(pipe_2);

            char str2[1024] = "";


            sleep(3);

            kill(child_1, SIGUSR1);
            kill(child_2, SIGUSR1);
            // 1b : pipe

            printf("EOF");
            wait(NULL);
            wait(NULL);
        }
        sleep(3);
        char str[1024] = "";
        //1a : signal
        printf("c2k\n");
        kill(getppid(), SIGUSR2);
        pause();
        // 2a: pipe
        printf("c2ka\n");
        printf("c2ka4\n");
        read(pipe_fd, str, sizeof(str));
        printf("[ %s ] ", str);


        return 0;

    }

    sleep(2);
    //1a : signal
    printf("c1k\n");
    kill(getppid(), SIGUSR1);
    pause();
    // 2a: pipe

    read(pipe_fd, str, sizeof(str));
    printf("[ %s ] ", str);

    return 0;


}