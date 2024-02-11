#include <stdio.h>
#include <stdlib.h>
// call it with some parameters from the command line like this
// ./a.out arg1 arg2 arg3

int main(int argc, char **argv)
//int argc = argument count
//char **argv = argument values. array of array of characters. ( argv[][] )
{
    int i;
    printf("Number of command line arguments are: %i\n", argc);
    for (i = 0; i < argc; i++) {
        printf("%i. argument is %s\n", i, argv[i]);
    }
    return 0;
}