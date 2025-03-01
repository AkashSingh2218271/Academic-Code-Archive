#include <stdio.h>
#include <math.h>

double fun(double x) {
    return x * x;
}

double simpsonsThreeByEightRule(double a, double b, int n) {

    if (n % 3 != 0) {
        printf("Error: Number of subintervals (n) must be a multiple of 3.\n");
        return -1;
    } 

    double h = (b - a) / n;
    double sum = fun(a) + fun(b);

    for (int i = 0; i < n; i++)
    {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * fun(x);
        } else {
            sum += 3 * fun(x);
        }
    }
    
    return (3 * h / 8) * sum;
}

int main() {
    double a, b;  // Limits of integration
    int n;        // Number of subintervals

    // Input values
    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    if (n <= 0 || n % 3 != 0) {
        printf("Error: The number of subintervals must be positive and a multiple of 3.\n");
        return 1;
    }

    // Calculate the integral
    double result = simpsonsThreeByEightRule(a, b, n);

    if (result != -1) {
        // Print the result
        printf("The approximate integral is: %.6lf\n", result);
    }

    return 0;
}