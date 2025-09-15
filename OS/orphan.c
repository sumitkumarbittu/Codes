#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
    perror("fork failed");
    return 1;
    }
    else if (pid == 0) {
    sleep(1);
    printf("Child process (PID=%d) running as orphan\n", getpid());
    }
    else {
    printf("Parent process (PID=%d) exiNng\n", getpid());
    }
    return 0;
}