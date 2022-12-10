#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    int pid_2_b_klld;
  int signal;

  if (argc != 2) {
	printf("Indique un numero de proceso\n");
	exit(2);
  }
  pid_2_b_klld = atoi(argv[1]);
  if (kill(pid_2_b_klld,0) == 0) {
	printf("El proceso con pid = %d existe\n",pid_2_b_klld);
  } else {
	printf("El proceso con pid = %d NO EXISTE\n",pid_2_b_klld);
  }
  return 0;
}