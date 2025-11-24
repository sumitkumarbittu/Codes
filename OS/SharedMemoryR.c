#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // Step 1: Generate the same key as sender
    key_t key = ftok("shmfile", 65);

    // Step 2: Locate the shared memory segment
    int shmid = shmget(key, 1024, 0666);

    // Step 3: Attach to shared memory
    char *str = (char *) shmat(shmid, NULL, 0);

    // Step 4: Read data
    printf("Data read from shared memory: %s\n", str);

    // Step 5: Detach and destroy shared memory
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}