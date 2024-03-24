//
// Created by rontap on 23/03/2024.
//
#include "librockpaperscissors.h"

void handler(int signal) {
    if (signal == SIGUSR1) {
        printf("[child %i] I won! ", getpid());
    } else if (signal == SIGTERM) {
        printf("[child %i] I lost Farewell!\n", getpid());
        exit(EXIT_SUCCESS);
    }
}

int main() {
    srand(getpid());
    char rps_pipe[20] = {"/tmp/rockpaper"};
    printf("[child %i] Is created!\n", getpid());
    struct sigaction sigact;
    sigact.sa_handler = handler;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = 0;
    sigaction(SIGTERM, &sigact, NULL);
    sigaction(SIGUSR1, &sigact, NULL);
    int round = 1;
    char data[MSG_LENGTH];

    while (1) {
        choice runtime_choice = rand() % 3;
        int rps_fd = open(rps_pipe, O_WRONLY);
        sprintf(data, "%i:%017d", runtime_choice, getpid());
        printf("[child %i] [round %i] chooses %s and sends this data to a pipe: %s\n", getpid(), round,
               results[runtime_choice], data);
        write(rps_fd, data, MSG_LENGTH);
        close(rps_fd);
        round++;
        pause();
    }
}