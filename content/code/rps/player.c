//
// Created by rontap on 23/03/2024.
//
#include "librockpaperscissors.h"

void handler(int signal) {

}

int main() {
    // TODO 1a: set up a random generator using `srand`. Look up `man srand`
    // This will let you generate random numbers

    // TODO 1b: choose a random number between 0-2, this is the choice. See the header file for #define-s
    // This will choose the rock , paper or scissors

    // TODO 2a: open up the pipe `/tmp/rockpaper` with write only
    // This will allow you to write the choice to the pipe

    // TODO 2b: format the string like this: choice:pid, but padded to length of 20
    // Hint: "%i:%017d" should be a format. Use `sprintf` Why?
    // The data needs to be formatted

    // TODO 2c: write your string using `write` to the opened file!

    // TODO 2d: close the file descriptor
    // Think about it, why is this needed? This would not be needed for `pipe`, only `mkfifo`

    // TODO 3a: wait for a signal using `pause` or `sigsuspend`
    // For the player to get the result from the runtime, we are pausing execution

    // TODO 3b: set up a signal handler using `sigaction` and a signal handler. (see: sigaction.c) Add cases for `SIGTERM` and `SIGUSR1`
    // To receive custom signals, we need to set up handlers and listen to them using `sigaction`

    // TODO 3c: in the handler file, set up actions for SIGTERM: close the application. SIGUSR1: continue and write message!
    // In the handler, you can define custom logic. SITERM means you lost, so you should exit.

    // TODO 4: wrap the logic for steps 1b - 2d in a infinite loop.
    // This way a player can play multiple times - until they lose.

    exit(EXIT_SUCCESS);
}