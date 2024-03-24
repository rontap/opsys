//
// Created by rontap on 22/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "librockpaperscissors.h"


/**
 * compile using `gcc runtime.c -o runtime`
 * useage: ./runtime [DELAY], where delay is the seconds between reads in a day. Defaults to zero.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    srand((long int) getpid());

    int round = 1;
    int original_participants = -1;
    int choices[MAX_PARTICIPANTS];
    int choice_pid[MAX_PARTICIPANTS];

    // optional delay
    char *pDelay;
    int delay = (int) strtol(argv[1], &pDelay, 10);
    if (delay < 0 || delay > 10) {
        delay = 0;
    }

    printf("[runtime] Welcome to Rock Paper Scissors Tournament.\n");
    unlink(rps_pipe);
    remove(rps_pipe);
    printf("[runtime] my pid is: %i . I am runnning with %i sec delay between reads. waiting to open fifo pipe..\n",
           getpid(), delay);
    int fid = mkfifo(rps_pipe, S_IRUSR | S_IWUSR);
    printf("[runtime] pipe is opened, waiting for input..\n");
    int rps_fd = -1;

    if (fid == -1) {
        printf("Error number: %i\n", errno);
        exit(EXIT_FAILURE);
    }

    rps_fd = open(rps_pipe, O_RDONLY);

    while (1) {
        printf("\n[runtime] === DAY %i Begins! ===\n", round++);
        int participants = 0;
        int eliminated_participants = 0;

        if (round > MAX_ROUNDS) {
            printf("[runtime] error : this game went on too far. Exiting.\n");
            exit(EXIT_FAILURE);
        }
        sleep(1);
        while (1) {
            sleep(delay);
            char msg[MSG_LENGTH] = {0};
            char *pEnd;
            printf("reading ");
            read(rps_fd, &msg, MSG_LENGTH);

            if (strnlen(msg, MSG_LENGTH) == 0) {
                printf("[runtime] no further applicants; commencing rock paper scissors..\n");
                break;
            }
            if (participants > MAX_PARTICIPANTS) {
                printf("[runtime] maximum participants (%i) reach", participants);
                break;
            }
            if (msg[1] != ':') {
                printf("[runtime] error: received a wrongly formatted message. It should be in format of CHOICE:PID. Was: %s\n",
                       msg);
                exit(EXIT_FAILURE);
            }


            choices[participants] = (int) (msg[0] - '0');
            choice_pid[participants] = (int) strtol(&msg[2], &pEnd, 10);
            printf(" number: %i, ", participants);
            printf(" pid:{%i}, ", choice_pid[participants]);
            printf("guess:");
            print_choice(choices[participants]);
            printf("\n");
            participants++;

        }

        if (original_participants == -1) {
            original_participants = participants;
        } else if (participants > original_participants) {
            printf("[runtime] error: it seems that now there are more participants then originally. This is a violation of the rules, exiting\n");
            exit(EXIT_FAILURE);
        }

        choice runtime_choice = choose();
        printf("[runtime] The gamemaster has chosen.. %s", results[runtime_choice]);
        printf("\n");
        for (int i = 0; i < participants; i++) {
            int pid = choice_pid[i];
            if (beats(runtime_choice, choices[i]) == BEATS) {
                printf("[runtime] player %i has lost becase %s beats %s. Eliminating him!\n", pid,
                       results[runtime_choice], results[choices[i]]);
                kill(pid, SIGTERM);
                eliminated_participants++;
            } else {
                printf("[runtime] player %i drawed or won, they can continue!\n", pid);
                kill(pid, SIGUSR1);
            }
        }

        printf("\n[runtime] The round has ended. Eliminated: %i/%i. %i remain.\n", eliminated_participants,
               participants,
               participants - eliminated_participants);

        if (participants == 0 || participants - eliminated_participants == 0) {
            printf("[runtime] it seems noone signed up for the game, or it is finished!  Writing it to log.\n");
            int return_fd = open(log_pipe, O_WRONLY);
            char log[100] = {""};
            sprintf(log, "time: %li, rounds: %i\n", time(NULL), round);
            write(return_fd, log, strlen(log));
            printf("[runtime] wrote to log, exiting.\n");
            exit(EXIT_SUCCESS);
        }

    }
}