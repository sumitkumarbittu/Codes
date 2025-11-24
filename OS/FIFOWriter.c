#include <stdio.h>      // printf, fgets
#include <fcntl.h>      // open
#include <sys/stat.h>   // mkfifo
#include <unistd.h>     // write

int main() {
    char message[100];

    // Create FIFO with name "myfifo"
    mkfifo("myfifo", 0666);

    // Take input from user
    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    // Open FIFO in write-only mode
    int fd = open("myfifo", O_WRONLY);

    // Write message into FIFO
    write(fd, message, sizeof(message));

    printf("Message sent successfully!\n");

    close(fd);  // Close FIFO
    return 0;
}