#include <stdio.h>
#include <math.h>

float valueOfEq(float x) {
    return (x * x * x) - x - 11;
}

float derivativeOfEq(float x) {
    return (3 * x * x) - 1;
}

void newtonRaphson(float initialGuess, int maxItr, float tolerance) {
    float x = initialGuess;
    float x_next;
    int i = 0;
    
    printf("Iteration %d: x = %f\n", i+1, x);
    
    while (i < maxItr) {
        float fx = valueOfEq(x);
        float fpx = derivativeOfEq(x);
        
        if (fabs(fpx) < 1e-6) {
            printf("Derivative is too small. The method may not converge.\n");
            return;
        }
        
        x_next = x - fx / fpx;
        
        printf("Iteration %d: x = %f\n", i+2, x_next);
        
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
    
    newtonRaphson(initialGuess, maxItr, tolerance);
    
    return 0;
}
