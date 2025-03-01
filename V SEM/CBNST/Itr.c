#include <stdio.h>
#include <math.h>

float g(float x) {
    return cbrt(x + 11); 
}

void fixedPointIteration(float initialGuess, int maxItr, float tolerance) {
    float x = initialGuess;
    float x_next;
    int i = 0;

    printf("Iteration %d: x = %f\n", i + 1, x);

    while (i < maxItr) {
        x_next = g(x); 

        printf("Iteration %d: x = %f\n", i + 2, x_next);

        if (fabs(x_next - x) <= tolerance) {
            printf("Root found: %f\n", x_next);
            return;
        }

        x = x_next; 
        i++;
    }

    printf("Root not found within %d iterations.\n", maxItr);
}

int main() {
    float initialGuess;
    int maxItr;
    float tolerance = 0.0001; // Tolerance for convergence

    printf("Enter initial guess: ");
    scanf("%f", &initialGuess);

    printf("Enter maximum number of iterations: ");
    scanf("%d", &maxItr);

    fixedPointIteration(initialGuess, maxItr, tolerance);

    return 0;
}
