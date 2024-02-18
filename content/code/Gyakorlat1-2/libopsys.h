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