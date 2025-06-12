#include <stdio.h>
#include <pthread.h>

// Function that will run in the thread
void* myThreadFunction(void* arg) {
    printf("Hello from the thread!\n");
    return NULL;
}

int main() {
    pthread_t thread;  // Declare a thread variable

    // Create a new thread
    if (pthread_create(&thread, NULL, myThreadFunction, NULL)) {
        printf("Error creating thread\n");
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    printf("Thread has finished execution\n");
    return 0;
}
