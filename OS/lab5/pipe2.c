#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int pipefds[2];
    char buffer[5];

    if (pipe(pipefds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    char *pin = "4128"; // PIN to send

    printf("Writing PIN to pipe...\n");
    write(pipefds[1], pin, strlen(pin)+1); // Write including NULL terminator
    printf("Done.\n\n");

    printf("Reading PIN from pipe...\n");
    read(pipefds[0], buffer, sizeof(buffer)); // Read back into buffer
    printf("Done.\n\n");

    printf("PIN from pipe: %s\n", buffer);

    return EXIT_SUCCESS;
}
