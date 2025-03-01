#include <stdio.h>
#include <math.h>

double fun(double x, double y) {
    return x + y;
}

void euler(double x0, double y0, double xn, int n) {
    double h = (xn - x0) / n;
    double x = x0, y = y0;

    printf("x\t\ty\n");
    printf("%.6lf\t%.6lf\n", x, y);
    
    for (int i = 0; i < n; i++)
    {
        y = y + h * fun(x, y);
        x = x + h;
        printf("%.6lf\t%.6lf\n", x, y);
    }

}

int main() {
    double x0, y0, xn; // Initial conditions and final x value
    int n;             // Number of steps

    // Input values
    printf("Enter the initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter the initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter the final value of x (xn): ");
    scanf("%lf", &xn);
    printf("Enter the number of steps (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: The number of steps must be positive.\n");
        return 1;
    }

    // Solve the ODE using Euler's Method
    euler(x0, y0, xn, n);

    return 0;
}