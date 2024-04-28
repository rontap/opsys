
# 2024 1. Beadandója

> Beadási határidő: 2024 április 7.

Tavasz van, közeledik a Húsvét. Nyuszi mama is készülődik, mégpedig a kis nyuszi fiúknak gyűjt locsoló versikéket. Ilyen gyöngyszemeket mint például: "Piros tojás zöld-fehér nyuszi, locsolásér jár két puszi!" Persze akad aki akár ezt is, kicsit másképp tudja. Minden módosított változatot amit hall, feljegyez.

Készítsen C nyelvű alkalmazást, ami segít Nyuszi mamának a locsoló versikék feljegyzésében 
- új verset tudjunk felvenni
- tudjuk listáztatni a már ismert verseket
- tudjunk törölni
- tudjunk módosítani egy meglévő verset. 

A locsoló verseket fájlban tároljuk.

Készítsen C  nyelvű programot ami  ezt a feladatot megoldja egy Linux rendszeren vagy WSL-en fut. A megoldást a beadási határidőt követő héten be kell mutatni a gyakorlatvezetőnek.

A forrásállományokat(egy kód + egy adatfájl) [itt töltsék fel zip formában.](https://canvas.elte.hu/courses/43790/assignments/337099?module_item_id=675787)

> Legkésöbbi beadási idő április 14; de ilyenkor egy jeggyel romlik az év végi jegy. Normál beadási határidő április 7.


## 2. Beadandó


Illés Tanárúr kiírta a második beadandót, beadási 
határideje Május 5. (illetve május 12 a végső határidő, 
egy jegy büntetéssel). 
Itt van a bővített leírása: 
Tavasz van, közeledik a Húsvét. 
Nyuszi mama is készült, mégpedig a kis nyuszi fiúknak gyűjtött locsoló versikéket. 
A Nyuszi Húsvét javában tart, a fiúk locsolni készülnek. fork: 
Nyuszi mama _(szülő / parent)_ a locsoló versikéket fájlban tárolja. 
Miközben ha új verset hall, azt továbbra is feljegyzi, esetleg módosítja, 
de a 4 nyuszi kisfia közül kiválasztja _(véletlenszám)_ a legrátermettebbet _(gyerek / child)_
 és elküldi locsolni a Barátfai nyuszi család lánytagjainak locsolására. 
Ez a Locsolás lehetőség jelenjen meg új menüpontként a korábbiak mellett. 

**signal és pipe: **
Mikor a nyuszi fiú megérkezik Barátfára küld egy jelzést _(signal)_ a mamának, 
aki erre válaszul 2 versikét is küld csövön _(pipe)_ keresztül a fiúnak. 
Ezeket a verseket a fiú képernyőre írja, majd választ egyet _(véletlenszám)_.

** message queue: ** 
A kiválasztott verset üzenetsoron _(message queue)_ visszaküldi a mamának. 
(Később ezt a verset már ne használják fel, tehát törlődik) 
Ezután nyuszi fiú elmondja Barátfán a verset 
(képernyőre írja, majd hozzá teszi: Szabad-e locsolni! 
Majd meglocsolja a lányokat és hazatér Nyuszi mamához. _(terminál)_ 
Készítsen C nyelvű programot ami ezt a feladatot megoldja, 
a megoldásnak WSL-en, vagy az opsys.inf.elte.hu kiszolgálón, 
vagy egy hozzá hasonló Linux rendszeren kell futnia. 
A megoldást a beadási határidőt követő héten be kell mutatni a gyakorlatvezetőnek. 

A forrásállományokat(egy kód + egy adatfájl) canvasban töltsétek fel.

# Értékelés

A számonkérésről részletesebben [[index#Számonkérés & Követelmények]]
#### Késve vagy hibásan beadadott beadandó

- Határidő után, de maximum 1 héttel késett feltöltés 1 jegy levonást jelent.
    - A határidő előtt a kérheted a határidő 2 hétre való hosszabbítását.
    - Ha addig sem töltesz fel beadandót, és nem is szólsz róla, akkor nem kaphatsz gyakorlati jegyet!
- A rosszul működő beadandó javításra lesz visszaküldve, de ez a kapott jegyet ez nem
  befolyásolja.
- Ha a több mint két hetet késel bármelyik beadandóddal, vagy a ZH-kat (és pótZH-kat) sem írtad meg, akkor nem
  kaphatsz jegyet (azaz 'nincs érdemjegye' kerül be neptunba).
- Ha a mindkét beadandódat késve adtad be, akkor is **csak egy jegy levonás jár**.

---

# Korábbi beadandók

#Korábbi  Ez gyakorlásnak itt hagyom, de a 2024/II félévhez **nem ezeket kell megoldani**

## 📈 Tavalyi Első Beadndó


Rendkívüli időket élünk.

Az "Igyál komám" szőlészetben is kopogtat a tavasz. Mint tudjuk a szőlő szereti a gondoskodást, a munkát, de leginkább a
munkást,
amit rendszerint jó terméssel hálál meg. Sok segítőre van szüksége a szőlészetnek, így a munkára jelentkezőknek egy
alkalmazás készül.

**EZ EGY KORÁBBI BEADANDÓ

Azok jelentkezését várja a gazdaság akik a tavaszi szezon heteiben tudnak munkát vállalni. A jelentkezés során meg kell
adni a
nevüket és azt, hogy a hét mely napjain tudnak menni dolgozni. A napokat ilyen formában adják meg: hétfő szerda
csütörtök.
A jelentkezők helyközzel választják el a napokat. A gazdaságnak megvan, hogy melyik napokon(hétfőnként, keddenként stb),
hány munkásra van szüksége. Ha egy napon már betelt a létszám, akkor arra a napra már ne fogadjon el jelentkezőt az
alkalmazás.

A jelentkezők adatait fájlban tároljuk, az adatfelvételen túl legyen lehetőségünk az
adatokon módosítani, törölni és szakmai alapon vagy teljes listát készíteni a jelentkezőkről.

Készítsen C nyelvű programot ami ezt a feladatot megoldja,
a megoldásnak vagy az WSL-en, vagy egy hozzá hasonló Linux
rendszeren kell futnia.

A megoldást a beadási határidőt követő héten be kell mutatni a gyakorlatvezetőnek.

**EZ EGY KORÁBBI BEADANDÓ Beadási határidő: 2023 április 10.**

## 📈 Tavalyi Második Beadndó

Az "Igyál komám" szőlészetben is kopogtat a tavasz. Mint tudjuk a szőlő szereti a gondoskodást, a munkát, de leginkább a
munkást, amit rendszerint jó terméssel hálál meg. Sok segítőre van szüksége a szőlészetnek, így a munkára jelentkezőknek
egy alkalmazás készül.

**EZ EGY KORÁBBI BEADANDÓ

Azok jelentkezését várja a gazdaság akik a tavaszi szezon heteiben tudnak munkát vállalni. Az adatok rendelkezésre
állnak, minden módosítást el tudunk végezni.

"Igyál komám" szőlészet (szülő folyamat) minden nap reggel megvizsgálja az aznapi jelentkezéseket, igényeket és
elindítja a dolgozókért a munkásjárato(ka)t. (gyerekfolyamat(ok)) Csak kisbusz áll rendelkezésre, ami max 5 főt tud
fuvarozni, és két darab kisbusz van. (A szőlészet kis cég, így nincs több napi munkás igény, mint 10 fő.) A szőlészet
elindítja a kisbusz(oka)t, akik, miután készek az indulásra, jelzést küldenek vissza, majd válaszul csövön keresztül
megkapják szőlészettől, hogy kiket kell munkára behozni. 

Ezt az információt a munkásjárat(ok) képernyőre is írják. Amint
beérnek a dolgozókkal, összegzésként üzenetsoron visszaküldik a szőlészetnek, hogy a kért dolgozók közül végül is hányat
sikerült behozni. Ezt a szőlészet képernyőre írja, majd befejezik a tevékenységet (munkásjárat gyerekfolyam terminál). A
szülő ezt megvárja, és ezzel készen áll a következő napi munkásjárat szervezésére. (Lehet újabb jelentkezőt felvenni,
módosítani, vagy egy újabb napi buszindítást kezdeni.)

Készítsen C nyelvű programot ami ezt a feladatot megoldja, egy Linux rendszeren kell futnia. A megoldást a beadási határidőt követő héten be kell mutatni a
gyakorlatvezetőnek.

**EZ EGY KORÁBBI BEADANDÓ**
