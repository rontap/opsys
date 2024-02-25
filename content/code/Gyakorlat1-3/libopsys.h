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

#ifndef LIBOPSYS_H
#define LIBOPSYS_H

int length(char *str) {
    int l = 0;
    while (*str++ != 0) {
        l++;
    }
    return l;
}

#endif //LIBOPSYS_H