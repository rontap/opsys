
## [Fileok letöltése](https://github.com/rontap/opsys/raw/main/content/code/Gyakorlat1-3/index.zip)

https://github.com/rontap/opsys/raw/main/content/code/Gyakorlat1-3/index.zip

## Fileok fordítása

```shell
 gcc -Wall -Werror=vla -pthread -lrt -std=c11 -pedantic -o a.out ./open_fopen.c && ./a.out text.txt
```

OS/X-en pedig:

```shell
 clang -Wall -Werror=vla  -std=c11 -pedantic -o a.out ./open_fopen.c && ./a.out text.txt
```

---
## Óra Outline

- [ ] /usr/include/**
- [ ] Új headerek `rand.c` srand!
- [ ] BASH `ls ll cd man tail head nano`
- [ ] flock --verbose -n /tmp/a -c 'cat 2> /tmp/a'
- [ ] `fcntl_0.c`
- [ ] `fcntl_0.c`
- [ ] Fixing `fcntl.c`
#FileControl 

### Seek

![[Pasted image 20240311002915.png]]