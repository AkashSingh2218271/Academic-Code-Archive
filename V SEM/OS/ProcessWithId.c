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
        printf("Child Process: My PID is %d, Parent PID is %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent Process: My PID is %d, Child PID is %d\n", getpid(), pid);
    }

    return 0;
}

