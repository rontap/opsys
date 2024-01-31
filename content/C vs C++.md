
![[Pasted image 20240131222558.jpg]]

- Szabad C++ -ben írni a beadandókat
- Javasolt C-ben írni. Hivatalosan nincs C++ tanítva


## Ha C++ -ben írod a beadandókat, az alábbiakra figyelj.

 **Ha nem tanultál C++-t külön az OEP-en túl, akkor szerintem jobban jársz C-vel.**  
Azoknak, akik C++-ban szeretnék megírni a beadandót és a ZH-t, **az alábbi módon kell megírni a beadandót**:  
- alapvetően C++11 vagy C++03 verzió közül lehet választani.  
- ahol van tanult C-s header/library, akkor azt kell használni. Vagyis 

```
<stdio> és <iostream> és <fstream> helyett <cstdio> -t. Ugyanígy <stdlib> és <string> helyett a <c*>- os megfelelő headert kell használni. Ez azt jelenti, hogy cin és cout-ot **NEM** lehet használni. 
random szám generálásra **lehet** a <random>-ot használni, <array> is lehet.
```

Egyéb, nem közvetlenül a tárgyon tanult dolgokra nyugodtan lehet bármilyen headert használni.  
- Ha esetleg elvi / gondolati hibát láttok, kérlek szóljatok, meggyőzhető vagyok.  
  
Ennek a feltételnek az a célja, hogy aki tud CPP-ben, az jobban otthon érezze magát, de a tárgyon tanult dolgokat ne tudja kikerülni.  

Fordítási paranc C++-ben példa

```shell
gcc -Wall -Werror=vla -pthread -std=c++11 -pedantic -o a_cpp  ./TE_FILEOD.cpp   -lrt
```

Ellenőrzés, hogy csak a megfelelő library-kat használtad-e:

```shell
cat TE_FILEOD.cpp | grep -E "<stdio>|<fstream>|<iostream>|<sstream>|<string>|cout|cin|ifstream|istream|stringbuf"`
```