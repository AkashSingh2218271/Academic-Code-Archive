#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    // Creating a child process
    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child Process: Listing files in the current directory:\n");
        execl("/bin/ls", "ls", NULL);
        printf("Child Process: execl failed!\n");
        exit(1);
    } else {
        // Parent process
        wait(NULL); // Parent waits for the child process to finish
        printf("Parent Process: Child process completed.\n");
    }

    return 0;
}

