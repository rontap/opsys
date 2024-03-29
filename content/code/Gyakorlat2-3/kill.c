#include "libopsys.h"

/**
 *
 * @param argc
 * @param argv
 * @details Task: Implement wrapper for kill
 * @return
 */
int main(int argc, char **argv) {
    /** usage:
     * kill SIGNAL PID
     */

    // 1. TODO: Add check that there are 2 arguments
    if (argc != 3) {
        printf("To use kill, add exactly two parameters.\n");
        printf("Usage: kill SIGNAL PID\n");
        exit(1);
    }

    if (false) {
        // 1b* TODO: extra task, optional
        // If there are no arguments, ask for a SIGNAL and PID from stdin
    }


    // 2. TODO: Add check that PID and kill signal is a number


    char *pid_overflow;
    char *signal_overflow;
    errno = 0;

    long int signal = strtol(argv[1], &signal_overflow, 10);
    long int pid = strtol(argv[2], &pid_overflow, 10);

    if (errno != 0 || *signal_overflow != '\0' || *pid_overflow != '\0') {
        printf("Errno error");
    }

    if (false) {
        printf("PID parameter should be a number.\n");
        exit(1);
    }

    errno = 0;
    kill(pid, signal);

    // 4. TODO: if signal returns with -1, that means there was an error

    // 4b TODO: extra task, optional
    // check the errno variable, and printf out a message. errno can have these values:
    // EINVAL The value of the sig argument is an invalid or unsupported signal number.
    // EPERM  The process does not have permission to send the signal to any receiving process.
    // ESRCH  No process or process group can be found corresponding to that specified by pid.


    return 0;
}