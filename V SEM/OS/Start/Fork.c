#include <stdio.h>
#include <unistd.h>  // For fork(), getpid(), and getppid()
#include <sys/types.h> // For pid_t

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("  Child PID: %d\n", getpid());
        printf("  Parent PID: %d\n", getppid());
    } else {
        // Parent process
        printf("Parent Process:\n");
        printf("  Parent PID: %d\n", getpid());
        printf("  Child PID: %d\n", pid);
    }

    return 0;
}
