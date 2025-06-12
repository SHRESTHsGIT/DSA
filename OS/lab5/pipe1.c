#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for pipe()

int main(void) {
    int pipefds[2]; // array to hold file descriptors

    // Create the pipe
    if (pipe(pipefds) == -1) {
        perror("pipe"); // if pipe fails
        exit(EXIT_FAILURE);
    }

    printf("Read End: %d\n", pipefds[0]);
    printf("Write End: %d\n", pipefds[1]);

    return EXIT_SUCCESS;
}
