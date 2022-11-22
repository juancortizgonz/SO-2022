#include "main.h"

void execmd(char **argv) {
    char *command = NULL;

    if (argv) {
        // get command
        command = argv[0];

        // execute command with execve
        if (execve(command, argv, NULL) == -1) {
            perror("Error:");
        };
    }
}