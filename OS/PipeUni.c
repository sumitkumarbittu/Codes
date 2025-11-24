// unidirectional_pipe.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char write_msg[100], read_msg[100];

    // Create a pipe
    pipe(fd);
    pid = fork();

    if (pid > 0) {  
        // Parent process
        close(fd[0]); // Close reading end
        printf("Parent: Enter a message for child: ");
        fgets(write_msg, sizeof(write_msg), stdin);
        write(fd[1], write_msg, strlen(write_msg) + 1); // include '\0'
        close(fd[1]);
    } 
    else {  
        // Child process
        close(fd[1]); // Close writing end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s", read_msg);
        close(fd[0]);
    }

    return 0;
}