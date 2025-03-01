#include <stdio.h>

float f(float x) {
    return x * x; 
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

    if (n % 3 != 0) {
        printf("Number of subintervals (n) must be a multiple of 3.\n");
        return 1;
    }

    h = (b - a) / n;
    integral = f(a) + f(b);

    for (i = 1; i < n; i++) {
        if (i % 3 == 0) {
            integral += 2 * f(a + i * h);
        } else {
            integral += 3 * f(a + i * h);
        }
    }

    integral = (3 * h / 8) * integral;

    printf("The value of the integral is: %.4f\n", integral);
    return 0;
}
