#include <stdio.h>
#include <unistd.h>  // For fork()
#include <sys/types.h> // For pid_t

int main() {
    pid_t pid;

    // Create a new process using fork()
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Code executed by the child process
        printf("Child Process:\n");
        printf("  Child PID: %d\n", getpid());
        printf("  Parent PID: %d\n", getppid());
    } else {
        // Code executed by the parent process
        printf("Parent Process:\n");
        printf("  Parent PID: %d\n", getpid());
        printf("  Child PID: %d\n", pid);
    }

    return 0;
}
