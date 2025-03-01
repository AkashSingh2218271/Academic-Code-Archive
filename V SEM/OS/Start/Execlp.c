#include <stdio.h>
#include <unistd.h> // For execlp()

int main() {
    printf("Before executing ls command using execlp()\n");

    // Execute the 'ls' command
    if (execlp("ls", "ls", "-l", NULL) == -1) {
        perror("execlp failed");
        return 1;
    }

    // This line will not be executed if execlp is successful
    printf("This line will not be printed if execlp() is successful.\n");

    return 0;
}
