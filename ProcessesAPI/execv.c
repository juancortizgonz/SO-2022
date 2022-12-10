#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *const argv[] = {"/bin/ls", "-l", NULL};
    execv(argv[0], argv);
    perror("Return from execv() not expected");
    exit(EXIT_FAILURE);
}