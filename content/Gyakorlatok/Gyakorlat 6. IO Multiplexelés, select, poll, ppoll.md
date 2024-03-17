
# Multitasking Bash-ben

új kombináció: `Ctrl+Z`
- fg
- bg
- & (háttérben indítás)
-  ` (while true; do date; sleep 1; done)`

![[Pasted image 20240317194636.png]]
# I/O Multiplexelés

File descriptorokra várás: `select` , `poll`
Mikor áll készen egy file?
- hagyományos file-oknál -> midig készen áll írásra vagy olvasásra
- pipie-ok és FIFO-k
	- Ha van olvasható adat, akkor `POLLIN`
	- Ha van lehetsőég írni akkor `POLLOUT`
	- Ha le van zárva az írás illetve olvasási vég: `POLLHUP` ill `POLLERR`

### Timeval (timeinterval)
```c
struct timeval { 
	time_t tv_sec; /* Seconds */
	 suseconds_t tv_usec; /* Microseconds (long int) */ 
};
```

### Select
- régebbi API, template-ekkel való kommunikálás, `int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);`
- pontos `timeval` struktúra
- visszatérési értékek
	- timeout: 0
	- hiba: -1
	- sikeres: pozitív, a készen lévő fd-k számával egyezik

## Poll
- újabb API, de ugyanaz kernel hívások
- egy struct-ba vannak a fd-k felsorolva

```c
struct pollfd { 
	int fd; /* File descriptor */ 
	short events; /* Requested events bit mask */ 
	short revents; /* Returned events bit mask */ 
};
int poll(struct pollfd fds[], nfds_t nfds, int timeout); 
/* timeout 0 = no block, -1 legalább egy, >0 várakozik
```

![[Pasted image 20240317183024.png]]


## Poll és Select hátrányai

- Ez egy `blocking` művelet, de nem lehet egyszerre signalra _vagy_ poll-ra szűrni.
- sok nyitott file esetén sok erőforrásba kerül ellenőrizni a file-okat.
- mindig az összes filedescriptort végignézik
- egy `struct` -on keresztül kommunikál a kernel oda és vissza -> performance!
- a kernel nem tartja nyilván speciálisan, hogy melyik fd-kre figyelünk, minden poll hívás egy új figyelést indít ell


## (p)select és (p)poll

```c
int pselect(
	int nfds, 
	fd_set *readfds, 
	fd_set *writefds, 
	fd_set *exceptfds, 
	struct timespec *timeout, 
	const sigset_t *sigmask
);

```

Atomikusan ekvivalens:

```c
sigset_t origmask; 
sigprocmask(SIG_SETMASK, &sigmask, &origmask); 
ready = select(nfds, &readfds, &writefds, &exceptfds, timeout); sigprocmask(SIG_SETMASK, &origmask, NULL); /* Restore signal mask */
```

# (e)select és (e)poll

- nem signalok segítségével, hanem egy speciális fd-követő fd-vel valósul meg
- flexibilisebb mint a signal alapú küldés
- nem UNIX kompatibilis
- lifecycle-je hasonló egy objektuméhoz.

létrehozás: `polls = int epoll_create()`
módosítás `int epoll_ctl(int epfd, int op, int fd, struct epoll_event *ev);` hozzáadjuk a epfd-figyelt listájához az fd-t `EPOLL_CTL_ADD` -al

Példa előkészítésre:
```c
int epfd; 
struct epoll_event ev;
epfd = epoll_create(5); 
if (epfd == -1) errExit("epoll_create"); 
ev.data.fd = fd; ev.events = EPOLLIN; 
if (epoll_ctl(epfd, EPOLL_CTL_ADD, fd, ev) == -1) errExit("epoll_ctl");
```
Várakosára:
`int epoll_wait(int epfd, struct epoll_event *evlist, int maxevents, int timeout);`

![[Pasted image 20240317185308.png]]

> Megjegyzés:
> Itt mindig akkor történt a feloldás, amikor az írás/olvasás a pipe-ból/ba lehetségessé vált. Ez a "Level-triggered" I/O
> Van lehetőség arra, hogy akkor oldódjon fel a parancs, amikor írás/olvasás _történt_ a pipe-ból/ba.
> Mi a különbség?


