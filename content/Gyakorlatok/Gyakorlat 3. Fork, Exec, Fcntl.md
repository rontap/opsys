## [Fileok letöltése](https://github.com/rontap/elteik-web/raw/main/teaching/opsys/materials/gy1/gy1-opsys.zip)

[https://github.com/rontap/elteik-web/raw/main/teaching/opsys/materials/gy01/gy1-opsys.zip](https://github.com/rontap/elteik-web/raw/main/teaching/opsys/materials/gy1/gy1-opsys.zip)

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