
# Órai feladat: Kő - papír - olló

Megoldandó feladat: egy három részből álló alkalmazást kell továbbfejleszteni / befejezni, Ami kő-papír olló versenyt szimulál.

A veresenyben tetszőleges számú játékos indul egy játékmester ellen. A játékosok beküldik a választott jelet a játékmesternek, és a játékmester is kiválasztja, hogy ő mit jelez vissza. A játékmester ezután visszaszól a játékosoknak, hogy vesztettek-e (ilyenkor kiesik a játékos) vagy döntetlen lett-e, esetleg nyert (ilyenkor a játékos folytathatja a mérkőzést.) A játékosok célja, hogy minél tovább játékban maradjanak!

Letöltés: Teams > General (Általános) > Files > Tananyagok > 7. Óra (Rock Paper Scissors)

## A játék komponensei

A három modul
- `player` - Az egyes játékos. Feladatai:
	- Kiválasztja, hogy mit mutat (kő, papír, olló)
	- pipe-on (csövön) átküldi a `tournament`-nek
	- signalra vár (jel). `SIGTERM` esetén leáll, `SIGUSR1` esetén továbbindul
- `runtime`
	- a nevezett játékosokat elindítja `fork` segítségével
	- a játék végén pipe-on (csövön) kap statisztikát a játékról a `tournament` felől, ezt kiírja egy paraméterként megadott file-ba.
- `tournament`
	- _Ez a komponens le van programozva_
	- Ez a komponens kapja meg a játékosok döntését, majd ez alapján jelet küld vissza a játékosoknak

## Fordítás:

- `./compile.sh` lefordítja az összes forrásfile-t!
- egy terminálban, előszőr a `runtime`-ot el kell indítani
- majd egy másik terminálban a `tournament` / `player` modult!

## A gyakorlat felépítése

- Két csoportra bomlik a gyakorlat, egyik része a `runtime` másik a `player` modulon dolgozik.
- Az óra utolsó 20 percében együtt átnézzük a megoldást.


### További feladatok (szorgalmi, gyakorlás)


> [!NOTE] Exploit amivel a játékos tud nyerni
> Van egy elvi hiba a `runtime.c`-ben elrejtve, amit ha csak egy játékos (`player`) indul ellene, könnyen ki tud az használni. Ezt a hibát ha kihasználja, akkor mindig tud nyerni. Hogyan?

> [!NOTE] Továbbfejlesztés
> Most a várakozás a `runtime.c`-ben hagyományos `sleep`-el van megoldva. Ez nem jó megoldás abban az esetben, ha sok játékos van (több száz), vagy a számítógép lassú. Jobb megoldás lenne `poll`-ra áttérni. Implementáld a javítást!

> [!NOTE] Exploit amivel a runtime nyer 
> Most nem csal a `runtime.c`, random választ mindig jelet. Módosísd a kiválasztást úgy, hogy mindig olyan jelet választ, amelyikkel a legtöbbet nyer!
