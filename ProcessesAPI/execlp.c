#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    execlp("ls", "ls", "-l", NULL);
    perror("Return from execlp() not expected");
    exit(EXIT_FAILURE);
}