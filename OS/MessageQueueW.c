#include <stdio.h>          // For printf, gets
#include <sys/ipc.h>        // For ftok()
#include <sys/msg.h>        // For msgget(), msgsnd()
#include <string.h>         // For strlen()

int main() {

    // Generate a unique key for message queue
    key_t key = ftok("msg", 65);

    // Create message queue or get its id
    int msgid = msgget(key, 0666 | IPC_CREAT);

    // Message buffer
    char message[100];

    // Take message from user
    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);   // Read from user

    // Send message to queue (no struct used)
    msgsnd(msgid, message, strlen(message) + 1, 0);

    printf("Message sent successfully!\n");

    return 0;
}