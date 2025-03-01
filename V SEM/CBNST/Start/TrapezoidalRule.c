#include <stdio.h>

double fun(double x) {
    return x * x;
}

double trapRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        sum += fun(x);
    }
    
    sum += (fun(a) + fun(b)) / 2.0;
    
    return sum * h;
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

    if (n <= 0) {
        printf("The number of subintervals must be positive.\n");
        return 1;
    }

    // Calculate integral
    double result = trapRule(a, b, n);

    // Print the result
    printf("The approximate integral is: %.6lf\n", result);

    return 0;
}