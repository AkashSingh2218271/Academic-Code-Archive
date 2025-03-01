#include <stdio.h>
#include <math.h>

double fun(double x) {
    return x * x;
}

double simpsonsOneByThreeRule(double a, double b, int n) {
    if (n % 2 != 0) {
        printf("Error: Number of subintervals (n) must be even.\n");
        return -1;
    }
    
    double h = (b - a) / n;
    double sum = fun(a) + fun(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * (fun(x));
        } else {
            sum += 4 * (fun(x));
        }
    }
    
    return (h/3) * sum;
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

    if (n <= 0 || n % 2 != 0) {
        printf("Error: The number of subintervals must be positive and even.\n");
        return 1;
    }

    // Calculate the integral
    double result = simpsonsOneByThreeRule(a, b, n);

    if (result != -1) {
        // Print the result
        printf("The approximate integral is: %.6lf\n", result);
    }

    return 0;
}
