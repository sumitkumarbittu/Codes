// msgqueue_sender.c
// A simple C program to send messages using System V Message Queues

#include <stdio.h>      // For input/output functions like printf and fgets
#include <stdlib.h>     // For exit() and other general-purpose functions
#include <string.h>     // For string handling functions like strcspn()
#include <sys/ipc.h>    // For IPC (Inter-Process Communication) key functions
#include <sys/msg.h>    // For message queue functions (msgget, msgsnd, etc.)

#define MSG_KEY 5555    // Define a unique key for the message queue

// Define a structure for message buffer
// It contains a message type (must be long) and the message text
struct msg_buffer {
    long msg_type;         // Message type (used by receiver to filter messages)
    char msg_text[100];    // Actual message text content
};

int main() {
    int msgid;                     // Message queue identifier
    struct msg_buffer message;     // Variable to hold the message

    // Create (or access) a message queue using a key
    // IPC_CREAT: Create queue if it doesn’t exist
    // 0666: Permission bits (read/write for everyone)
    msgid = msgget(MSG_KEY, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget failed");   // Print error if queue creation/access fails
        exit(1);
    }

    message.msg_type = 1;          // Assign a message type (must be > 0)

    // Prompt user to enter a message
    printf("Enter message to send: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);  // Read input from user

    // Remove newline character at the end (added by fgets)
    message.msg_text[strcspn(message.msg_text, "\n")] = '\0';

    // Send the message to the queue
    // msgsnd() arguments:
    // msgid: Queue ID
    // &message: Pointer to message structure
    // sizeof(message.msg_text): Size of the text to send
    // 0: No special flags
    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd failed");   // Print error if sending fails
        exit(1);
    }

    // Print confirmation
    printf("Message sent: %s\n", message.msg_text);

    return 0;   // Exit successfully
}
