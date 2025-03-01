#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Creating a child process
    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    } else if (pid == 0) {
        // Child process
        printf("This is the Child Process.\n");
    } else {
        // Parent process
        printf("This is the Parent Process.\n");
    }

    return 0;
}
