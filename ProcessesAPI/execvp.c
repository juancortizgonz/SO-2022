#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *const cmd[] = {"ls", "-l", NULL};
    execvp(cmd[0], cmd);
    perror("Return from execvp() not expected");
    exit(EXIT_FAILURE);
}
