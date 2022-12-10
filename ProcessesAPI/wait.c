#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("Hola mundo (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child new process
        printf("hello, i'm child (pid:%d) \n", (int) getpid());
    } else {
        // parent goes down this path
        int rc_wait = wait(NULL);
        printf("hello, i'm parent of %d (rc_wait:%d) (pid:%d) \n",
                rc, rc_wait, (int) getpid());
    }
    
    return 0;
}