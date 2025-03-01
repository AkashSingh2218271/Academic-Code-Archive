#include <stdio.h>

float f(float x) {
    return x * x; // Example function: f(x) = x^2
}

int main() {
    int n, i;
    float a, b, h, integral;

    printf("Enter the lower limit (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit (b): ");
    scanf("%f", &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    h = (b - a) / n;
    integral = (f(a) + f(b)) / 2.0;

    for (i = 1; i < n; i++) {
        integral += f(a + i * h);
    }

    integral *= h;

    printf("The value of the integral is: %.4f\n", integral);
    return 0;
}
