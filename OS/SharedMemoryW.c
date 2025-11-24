#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    // Step 1: Generate a unique key
    key_t key = ftok("shmfile", 65);

    // Step 2: Create shared memory segment
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Step 3: Attach to shared memory
    char *str = (char *) shmat(shmid, NULL, 0);

    // Step 4: Write data
    printf("Enter data to send: ");
    fgets(str, 1024, stdin);

    printf("Data written to shared memory: %s\n", str);

    // Step 5: Detach from shared memory
    shmdt(str);

    return 0;
}