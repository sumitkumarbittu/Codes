#include <stdio.h>      // printf
#include <fcntl.h>      // open
#include <sys/stat.h>   // mkfifo
#include <unistd.h>     // read

int main() {
    char buffer[100];

    // Create FIFO (if not created already)
    mkfifo("myfifo", 0666);

    // Open FIFO in read-only mode
    int fd = open("myfifo", O_RDONLY);

    // Read the message from FIFO
    read(fd, buffer, sizeof(buffer));

    printf("Received message: %s\n", buffer);

    close(fd);  // Close FIFO
    return 0;
}