//
// Created by rontap on 22/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>

#include <signal.h>

#ifndef CODE_LIBROCKPAPERSCISSORS_H

#define CODE_LIBROCKPAPERSCISSORS_H

#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define NUMBER_OF_CHOICES 3

#define result int
#define choice int
#define BEATS (1)
#define DRAW (0)
#define LOSES (-1)

#define MSG_LENGTH  20
#define MAX_ROUNDS 99
#define MAX_PARTICIPANTS 999

/**
 * Main Rock Paper Scissors Pipe. This is created and maintained by runtime.c
 * Player.c should write to this
 */
char rps_pipe[20] = {"/tmp/rockpaper"};
/**
 * Logging pipe. This should be created by tournament.c and will be written to by runtime.c
 */
char log_pipe[20] = {"/tmp/rocklog"};

/**
 * The different results, printing out for niceness.
 * Usage: printf("%s", results[my_result_number]);
 */
char results[4][8] = {"rock", "paper", "scissors"};

result beats(choice a, choice b) {
    if (a == b) return DRAW;
    if (a == ROCK && b == SCISSORS) return BEATS;
    if (a == SCISSORS && b == PAPER) return BEATS;
    if (a == PAPER && b == ROCK) return BEATS;
    return LOSES;
}

choice choose() {
    return rand() % NUMBER_OF_CHOICES;
}

void print_choice(choice a) {
    if (a == ROCK) printf("rock");
    if (a == SCISSORS) printf("scissors");
    if (a == PAPER) printf("paper");
}


#endif //CODE_LIBROCKPAPERSCISSORS_H
