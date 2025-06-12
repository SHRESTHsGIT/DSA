#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int rc = fork();

    if (rc < 0) {
        printf("fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child process (pid: %d)\n", getpid());
    } else {
        int status;
        waitpid(rc, &status, 0); // wait for *specific* child (rc = child pid)
        printf("Parent finished waiting for child (pid: %d)\n", rc);
    }
}
