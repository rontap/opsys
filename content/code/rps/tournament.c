//
// Created by rontap on 23/03/2024.
//

#include "librockpaperscissors.h"

int main(int argc, char **argv) {

    // TODO 1: the first argument (after filename) should be read and converted to int using `strtol`.
    // This number will be the amount of participants. This value should default to 10

    // TODO 2a: `fork` as many times as it was given in the argument. Beware not to create a fork bomb!
    // This will allow you to start multiple processes

    // TODO 2b: using `execv` or `system`, start the `./player` process!
    // This will change the process from `tournament` to `player`. The execution of this program ends when callin execv

    // TODO 3a the parent process should continue and create a new pipe with the name of `char log_pipe[20] = {"/tmp/rocklog"};` use `mkfifo` !
    // The parent will log down some results from the tournament. They use a pipe for this

    // TODO 3b test for the result of mkfifo. If it is -1, you should display an error.
    // This way it becomes much easier to test for errors.

    // TODO 3c open this pipe for read only
    // Since we are only receiving from the runtime, we only need to open it for reading

    // TODO 3d read up to 100 characters from it
    // Why is it not good practice that there is a fixed amount of characters to read? How would you improve this later?

    // TODO 3e before calling `mkfifo`, `remove` and `unlink` the file!
    // This is needed because if the program ends prematurely, the files will still be here. If you did step 3b properly, this solves the issues.

    // TODO 4a open a file called `rockpaper.log` using `open`. Use the flags such that the file is opened for write and append.
    // We want to append because we are logging many tournaments.

    // TODO 4b write the data previously read from the pipe to the file, then close both files.
    // If we dont close the files, the kernel may not know that other processes are allowed to read/write them

    // TODO 5 wait for all child processes to end using `wait`
    // If you dont wait for it, child processes can become `zombie` processes - The kernel does not know if they can be cleaned up.
}