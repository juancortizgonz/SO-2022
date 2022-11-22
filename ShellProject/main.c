#include "main.h"

int main(void) {
    char *full_command = NULL, *copy_command = NULL;
    size_t n = 0;
    ssize_t nchars_read;  // num of characters that user types
    char *token;
    const char *delim = " \n";
    char **argv;
    int i = 0;  // x = 0
    int num_tokens = 0;

    // print a prompt for the user to type in
    printf("$ ");

    // get the string that user types in and pass it to the function
    nchars_read = getline(&full_command, &n, stdin);

    // allocate space to store characters read by getline
    copy_command = malloc(sizeof(char) * nchars_read);

    if (copy_command == NULL) {
        perror("tsh: memory allocation error");
        return (-1);
    }

    // make a copy of the command
    strcpy(copy_command, full_command);

    // check if getline function failed
    if (nchars_read == -1) {
        printf("Exiting shell...\n");
        return (-1);
    } else {
        // split the string into an array of words
        token = strtok(full_command, delim);

        while (token != NULL) {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;
        // printf(">>>>> %d \n", num_tokens);

        /* use malloc to allocate enough space for the pointer to the argument variables */
        argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(copy_command, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            // printf(">>>>> %s \n", argv[i]);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        // execute commands with execv


        free(argv);
        free(full_command);
        free(copy_command);
    }

    return (0);
}