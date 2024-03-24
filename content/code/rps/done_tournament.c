//
// Created by rontap on 23/03/2024.
//

#include "librockpaperscissors.h"

int main(int argc, char **argv) {
    char log_pipe[20] = {"/tmp/rocklog"};

    unlink(log_pipe);
    remove(log_pipe);
    int fid = mkfifo(log_pipe, S_IRUSR | S_IWUSR);

    if (fid == -1) {
        printf("Error number: %i\n", errno);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 99; i++) {
        int ch = fork();
        if (ch == 0) {
            char *arg[] = {"./player", NULL};
            execv("./player", arg);
            break;
        }
    }

    printf("[tournament] opening log file!\n");
    int rps_fd = open(log_pipe, O_RDONLY);
    char log[100] = {""};
    read(rps_fd, log, sizeof(log));
    printf("[tournament] read:%s\n", log);
    int log_fd = open("rockpaper.log", O_WRONLY | O_APPEND);
    write(log_fd, log, strlen(log));

    close(rps_fd);
    close(log_fd);
    printf("[tournament] finishing log files!\n");

    int status;
    wait(&status);
}