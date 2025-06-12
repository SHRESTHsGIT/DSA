#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t rw_mutex;     // For writers or first/last reader
pthread_mutex_t mutex; // For reader_count
int reader_count = 0;
int shared_data = 0;  // Simulated shared resource

void* reader(void* arg) {
    int id = *(int*)arg;

    // Entry section
    pthread_mutex_lock(&mutex);
    reader_count++;
    if (reader_count == 1)
        sem_wait(&rw_mutex);  // First reader locks the resource
    pthread_mutex_unlock(&mutex);

    // Critical section (reading)
    printf("Reader %d is reading shared_data = %d\n", id, shared_data);
    sleep(1);

    // Exit section
    pthread_mutex_lock(&mutex);
    reader_count--;
    if (reader_count == 0)
        sem_post(&rw_mutex);  // Last reader unlocks the resource
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;

    // Writer wants exclusive access
    sem_wait(&rw_mutex);

    // Critical section (writing)
    shared_data += 1;
    printf("Writer %d is writing... New shared_data = %d\n", id, shared_data);
    sleep(2);

    sem_post(&rw_mutex);  // Release resource
    return NULL;
}

int main() {
    pthread_t r1, r2, w1, w2;
    int id1 = 1, id2 = 2, id3 = 1, id4 = 2;

    // Init semaphores and mutex
    sem_init(&rw_mutex, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&w1, NULL, writer, &id3);
    pthread_create(&r2, NULL, reader, &id2);
    pthread_create(&w2, NULL, writer, &id4);

    // Wait for threads to complete
    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w2, NULL);

    // Clean up
    sem_destroy(&rw_mutex);
    pthread_mutex_destroy(&mutex);

    return 0;
}
