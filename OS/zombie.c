#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child process (PID=%d) exiting immediately\n", getpid());
        exit(0);
    }
    else {
        sleep(1);
        printf("Parent process (PID=%d) finished sleeping\n", getpid());
    }
    return 0;
}