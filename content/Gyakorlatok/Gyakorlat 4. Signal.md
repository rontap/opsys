

# 4. Óra Pipe


## Fileok fordítása

```shell
 gcc -Wall -Werror=vla -pthread -lrt -std=c11 -pedantic -o a.out ./signal.c && ./a.out 
```

OS/X-en pedig:

```shell
 clang -Wall -Werror=vla -pthread -std=c11 -pedantic -o a.out ./signal.c && ./a.out 
```

## Óra Outline

- [ ] Mik a Signal-ok?
- [ ] hogyan küldünk signaolokat `Signal / signal.c`
- [ ] `killable`  kill -s SIGSEGV 441
- [ ] stty -e
- [ ] rendes signalok `Signal / sigaction.c`
- [ ] `kill.c` / errno


## Signalok

- `SIGINT` Ctrl C
- `SIGTERM` hagyományos leállás
- `SIGSTOP`  - nem fedhető
- `SIGKILL` - nem fedhető
- `SIGSEGV` - Szegmentációs hiba


![[Pasted image 20240309193926.png]]
Kód lefolyása signal esetén

### Signal Küldés


PID = Process ID, a proessz egyedi azonosítója
Például a szülő program megölése:

```c
pid_t pid = getppid();
kill(pid,SIGTERM);
```

### Signal Handler (sigaction)

Egy nem 'elkapott' signal leállítja a processt.
Ahhoz, hogy egy process lekezelje a signalt, a következőt kell beállítani:

```c
void handler(int signumber) {
printf("[handler] %i\n", signumber);
}

struct sigaction sigact;
sigact.sa_handler = handler; 
sigemptyset(&sigact.sa_mask);
sigact.sa_flags = 0; 

sigaction(SIGTERM, &sigact, NULL);
```

Itt a `SIGTERM` signal nem leálltja az alkalmazást, hanem meghívja a handlert. Miután a handler lefutott, folyik a
program futása.  
Vannak signalok, amiket nem lehet 'elkapni', ilyen pl a `SIGKILL`.

