#define REGIONS 5
#define GOOD_WINE_EXTRA 0.5
void handler(int signal) {

}
int child_krampus(int wine_sum) {
  int parent = getppid();
  kill(parent,SIGUSR1);
}
int get_random_int_up_to(int up_to) {
 
}
int main(int argc, char** argv) {
 char[] = {"Szekszárdi","Badacsonyi","Egri","Tokaji", "Somlo" };
 srand(time(NULL));
 int pipe_from_parent[2];
 pipe_from_parent  = pipe();
 int wine_sum = atoi(argv[1]);
 int wine_1 = wine_sum / 2;
 int wine_2 = wine_sum / 2;
 if (wine_sum % 2 != 0)
  wine_2++;
 }
 int fork1 = fork();
 if (fork1 == -1) {
  exit(1);
 }
 if (fork1 >= 0) {
  // we are in the parent
  int fork2 = fork();
  if (fork2 == 0) {
   exit(1);
  }
  if (fork2 >= 0) {
   // we are still in the parent
   wait(NULL);
   wait(NULL);
  } else {
   // we are in the child1
   child_krampus(wine_1);
  }
 } else {
  // we are in the child2
  child_krampus(wine_2);
 }
}
/* 
 1a. NSZT Mikulás (szülő) kiválaszt a legjobb területek 
	(Szekszárdi borvidék, Badacsonyi borvidék, Egri borvidék, Tokaji borvidék és Somló) 
	közül kettőt véletlenszerűen, 
 1b. majd elküldi egy-egy krampuszát, boros futárát (gyerek folyamat) 
	a kiválasztott pincészethez új borért. 
 1c. NSZT paraméterként kapja meg, hány vendég lesz a Mikulás ünnepségen. 
	fejenként 1 liter borral számol, 
 1d. így csövön elküldi a krampuszainak, egyrészt, hogy melyik pincészetbe kell 
	menni, és azt, hogy hány liter újbort hozzanak. 
 1e.  Krampuszok miután vették az "adást", kiírják a képernyőre azt, 
	visszaküldenek NSZT-nek egy jelzést, hogy a bor vételezés elindult, 
	majd terminálnak. 
 1f. A szülő miután vette a jelzést, képernyőre írja, 
	hogy melyik terület vételezése indult el, 
	majd megvárja a gyerekfolyamatok végét, utána terminál.
*/

/*
 2a. A krampuszok "Sommeriel" (borszakértő) végzettséggel is rendelkeznek, 
	így a pincészetbe érve először megkóstolják a termést. 
	A kóstolás eredményét (véletlenszerűen eldönti, hogy arany vagy ezüstérmes minősítést kapna ez a bor) 
 2b. visszaírják üzenetsoron a szülőnek (Mikulásnak), 
	hogy milyen minősítésű a bor. 
 2c. Szülő ezeket a képernyőre írja és befejezik a tevékenységüket, terminálnak.
*/

/*
 3a. Mikulás miután megkapta minősítéseket, arra gondol, 
	hogy ha nagyon finom a termés, akkor többet kellene krampuszokkal hozatni, 
	mert a jó jobban csúszik, nehogy probléma legyen. 
	Ha aranyérmesre minősíti a krampusz a bort, 
	akkor automatikusan 50%-al többet hoz, az eredeti rendeléshez képest. 
 3b. A mennyiséget (eredetit vagy a növeltet) 
	osztott memóriába és a képernyőre is kiírja.
*/

/*
 4a. A közös memória használat veszélyes, 
	védje szemaforral a memóriába írást. 
 4b. Majd az ünnepi italok beérkezése után Mikulás összegezve kiírja, 
	hogy melyik szőlővidékről végül mennyi bor is érkezett.
*/
