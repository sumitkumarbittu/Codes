// bidirectional_pipe.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1[2], fd2[2];
    pid_t pid;
    char parent_msg[100], child_msg[100];

    pipe(fd1); // for parent -> child
    pipe(fd2); // for child -> parent

    pid = fork();

    if (pid > 0) {
        // Parent process
        close(fd1[0]); // Close read end of first pipe
        close(fd2[1]); // Close write end of second pipe

        printf("Parent: Enter a message for child: ");
        fgets(parent_msg, sizeof(parent_msg), stdin);

        write(fd1[1], parent_msg, strlen(parent_msg) + 1);
        close(fd1[1]);

        read(fd2[0], child_msg, sizeof(child_msg));
        printf("Parent received reply: %s", child_msg);
        close(fd2[0]);
    } 
    else {
        // Child process
        close(fd1[1]); // Close write end of first pipe
        close(fd2[0]); // Close read end of second pipe

        read(fd1[0], parent_msg, sizeof(parent_msg));
        printf("Child received: %s", parent_msg);

        printf("Child: Enter reply to parent: ");
        fgets(child_msg, sizeof(child_msg), stdin);

        write(fd2[1], child_msg, strlen(child_msg) + 1);
        close(fd2[1]);
    }

    return 0;
}