

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

#define REGIONS 5
#define GOOD_WINE_EXTRA 0.5
#define MESSAGE_QUEUE_NAME "/my_queue2"
#define MSG_LENGTH 10
#define REGION_LENGTH 12
#define MQ_LENGTH 50

int pipe_from_parent[2];
int pipe_to_parent[2];
mqd_t message_queue;
char regions[REGIONS][12] = {"Szekszárdi", "Badacsonyi", "Egri", "Tokaji", "Somlo"};
char quality[2][12] = {"Silver", "Gold"};
int sem_id;
int shm_id;
int *shm_content;

void modify_semaphore(int semid, int operation)
{
  struct sembuf action;

  action.sem_num = 0;
  action.sem_op = (short)operation;
  action.sem_flg = 0;

  if (semop(semid, &action, 1) < 0)
    perror("semop");
}

int ascii_to_int(char ascii)
{
  return (int)ascii - 48;
}

void handler(int signal)
{
}
void child_krampus(int sleep_time)
{
  srand(time(NULL) + sleep_time);
  close(pipe_from_parent[STDOUT_FILENO]);
  char msg[MSG_LENGTH] = "";
  char *pEnd;
  read(pipe_from_parent[STDIN_FILENO], &msg, MSG_LENGTH);

  int region_number = ascii_to_int(msg[0]);
  int wine_number = (int)strtol(&msg[2], &pEnd, MSG_LENGTH);
  int is_quality = rand() % 2;

  sleep(sleep_time);
  int parent = getppid();

  char str[MSG_LENGTH] = "";
  sprintf(str, "%d", is_quality);
  mq_send(message_queue, str, MSG_LENGTH, 4);

  if (is_quality == 1)
  {
    wine_number = wine_number + wine_number / 2;
  }
  printf("[Krampus] Region: %s, Liters: %i, Quality: %s\n", regions[region_number], wine_number, quality[is_quality]);

  modify_semaphore(sem_id, -1);
  shm_content = (int *)shmat(shm_id, NULL, 0);
  shm_content[0] += wine_number;
  shmdt(shm_content);
  modify_semaphore(sem_id, 1);

  kill(parent, SIGUSR1);
}
int get_random_region()
{
  return rand() % REGIONS;
}
int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Required argument count 1\n");
    exit(1);
  }

  // SIGNALS
  struct sigaction sigact;
  sigact.sa_handler = handler;
  sigemptyset(&sigact.sa_mask);
  sigact.sa_flags = 0;
  sigaction(SIGUSR1, &sigact, NULL);
  sigaction(SIGUSR2, &sigact, NULL);

  // MQ
  struct mq_attr attr;
  attr.mq_maxmsg = 5;
  attr.mq_msgsize = MQ_LENGTH;

  mq_unlink(MESSAGE_QUEUE_NAME);
  message_queue = mq_open(MESSAGE_QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);
  if (message_queue < 0)
  {
    exit(1);
  }

  // RNADOM, REGION
  srand(time(NULL));
  int wine_sum = atoi(argv[1]);
  int wine_1 = wine_sum / 2;
  int wine_2 = wine_sum / 2;
  if (wine_sum % 2 != 0)
    wine_2++;

  int region_1 = get_random_region();
  int region_2;
  do
  {
    region_2 = get_random_region();
  } while (region_1 == region_2);

  // PIPE
  pipe(pipe_from_parent);

  // SHM & SEM
  key_t key;
  key = ftok(argv[0], 51);
  shm_id = shmget(key, MSG_LENGTH, IPC_CREAT | S_IRUSR | S_IWUSR);
  sem_id = semget(key, 1, IPC_CREAT | S_IRUSR | S_IWUSR);
  semctl(sem_id, 0, SETVAL, 1);

  // FORK
  int fork1;
  fork1 = fork();
  if (fork1 == -1)
  {
    exit(1);
  }
  if (fork1 > 0)
  {
    // we are in the parent
    int fork2 = fork();
    if (fork2 == -1)
    {
      exit(1);
    }
    else if (fork2 > 0)
    {
      // we are still in the parent
      close(pipe_from_parent[STDIN_FILENO]);
      close(pipe_from_parent[STDIN_FILENO]);

      char str[MSG_LENGTH] = "";
      sprintf(str, "%d:%d", region_1, wine_1);
      write(pipe_from_parent[STDOUT_FILENO], str, MSG_LENGTH);
      pause();
      printf("[nicolaus] Region %s started\n", regions[region_1]);
      sprintf(str, "%d:%d", region_2, wine_2);
      write(pipe_from_parent[STDOUT_FILENO], str, MSG_LENGTH);
      pause();
      printf("[nicolaus] Region %s started\n", regions[region_2]);

      char quality_1[MSG_LENGTH-1] = "";
      char quality_2[MSG_LENGTH-1] = "";
      mq_receive(message_queue, quality_1, MQ_LENGTH, 0);
      mq_receive(message_queue, quality_2, MQ_LENGTH, 0);
      printf("[nicolaus MQ] Region: %s; Quality: %s\n", regions[region_1], quality[ascii_to_int(quality_1[0])]);
      printf("[nicolaus MQ] Region: %s; Quality: %s\n", regions[region_2], quality[ascii_to_int(quality_2[0])]);

      wait(NULL);
      wait(NULL);

      modify_semaphore(sem_id, -1);
      shm_content = (int *)shmat(shm_id, NULL, 0);
      printf("[nicolaus SHM] Final Results: %i\n", shm_content[0]);
      modify_semaphore(sem_id, 1);

      mq_close(message_queue);
      mq_unlink(MESSAGE_QUEUE_NAME);
      shmctl(shm_id, IPC_RMID, NULL);
      semctl(sem_id, 0, IPC_RMID);
    }
    else
    {
      // we are in the child1
      child_krampus(0);
    }
  }
  else
  {
    // we are in the child2
    child_krampus(1);
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
