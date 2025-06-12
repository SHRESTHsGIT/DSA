#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // for wait()

int main(void) {
    int pipefds[2];
    char buffer[5];

    if (pipe(pipefds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork(); // Create a child process

    if (pid == 0) { // Child Process
        char *pin = "4821";
        close(pipefds[0]); // Close reading end in child
        write(pipefds[1], pin, 5); // Write PIN to pipe
        printf("Child: Sent PIN to parent.\n");
        exit(EXIT_SUCCESS);
    } else if (pid > 0) { // Parent Process
        wait(NULL); // Wait for child
        close(pipefds[1]); // Close writing end in parent
        read(pipefds[0], buffer, 5); // Read PIN from pipe
        printf("Parent: Received PIN '%s'\n", buffer);
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
