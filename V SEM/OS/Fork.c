#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;

    // Creating the first child process
    pid1 = fork();

    if (pid1 < 0) {
        printf("Fork failed!\n");
        exit(1);
    } else if (pid1 == 0) {
        // First child process
        printf("First Child Process: My PID is %d, Parent PID is %d\n", getpid(), getppid());
        sleep(5);  // Simulate some work being done by the child
        printf("First Child Process: My PID is %d, Parent PID is %d (after sleep)\n", getpid(), getppid());
    } else {
        // Parent process
        pid2 = fork();  // Creating a second child process

        if (pid2 < 0) {
            printf("Fork failed!\n");
            exit(1);
        } else if (pid2 == 0) {
            // Second child process
            printf("Second Child Process: My PID is %d, Parent PID is %d\n", getpid(), getppid());
            sleep(2);  // Simulate some work being done by the child
        } else {
            printf("Parent Process: Terminating before children.\n");
            exit(0);  // Parent process terminates
        }
    }

    return 0;
}
