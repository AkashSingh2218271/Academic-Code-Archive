#include <stdio.h>
#include <unistd.h> // For execlp()

int main() {
    printf("Before executing dir command using execlp()\n");

    // Execute the 'dir' command using Windows' command shell
    if (execlp("cmd", "cmd", "/c", "dir", NULL) == -1) {
        perror("execlp failed");
        return 1;
    }

    // This line will not execute if execlp succeeds
    printf("This line will not be printed if execlp() is successful.\n");

    return 0;
}
