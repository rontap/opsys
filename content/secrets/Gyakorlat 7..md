# 7. Óra /  Gy03 / Pipe & Mkfifo

## [Új Fileok letöltése](https://github.com/rontap/elteik-web/raw/main/teaching/opsys/materials/gy3/gy03.zip)

[https://github.com/rontap/elteik-web/raw/main/teaching/opsys/materials/gy3/gy03.zip](https://github.com/rontap/elteik-web/raw/main/teaching/opsys/materials/gy3/gy03.zip)

---
[Kezdőlap](index.md)
|
[Vissza](Gyakorlat%206..md)
|
[Tovább](Gyakorlat%208..md)

## Előző részek tartalmából

## Fileok fordítása

```shell
 gcc -Wall -Werror=vla -pthread -std=c11 -pedantic -o a.out ./signal.c -lrt  && ./a.out 
```

OS/X-en pedig:

```shell
 clang -Wall -Werror=vla -pthread -std=c11 -pedantic -o a.out ./signal.c  && ./a.out 
```

## Óra Outline

- [ ] beadandó schedule
- [ ] pipe bevezető
- [ ] `pipe.c`
- [ ] `mkfifo.c` és társai

[Kezdőlap](index.md)
|
[Vissza](Gyakorlat%206..md)
|
[Tovább](Gyakorlat%208..md)
