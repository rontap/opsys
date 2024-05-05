```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <mqueue.h>
#include <signal.h>
#include <semaphore.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>

void handler(int signal) {

}
int main() {
	exit(0);
}
```

Fordítási parancs:

```bash
gcc -Wall zh.c -lrt -pthread
```