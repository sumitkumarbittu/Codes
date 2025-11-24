#include <stdio.h>          // For printf
#include <sys/ipc.h>        // For ftok()
#include <sys/msg.h>        // For msgget(), msgrcv()

int main() {

    // Generate same key as sender
    key_t key = ftok("msg", 65);

    // Get message queue ID
    int msgid = msgget(key, 0666 | IPC_CREAT);

    // Buffer to store received message
    char buffer[100];

    // Receive message (msgtype = 0 → receive any)
    msgrcv(msgid, buffer, sizeof(buffer), 0, 0);

    // Display message
    printf("Received Message: %s\n", buffer);

    // Remove message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}