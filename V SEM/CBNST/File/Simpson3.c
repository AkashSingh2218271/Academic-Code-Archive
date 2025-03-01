#include <stdio.h>

float f(float x) {
    return x * x;
}

int main() {
    int n, i;
    float a, b, h, integral, oddSum = 0.0, evenSum = 0.0;

    printf("Enter the lower limit (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit (b): ");
    scanf("%f", &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Number of subintervals (n) must be even.\n");
        return 1;
    }

    h = (b - a) / n;

    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
            evenSum += f(a + i * h);
        } else {
            oddSum += f(a + i * h);
        }
    }

    integral = (h / 3) * (f(a) + 4 * oddSum + 2 * evenSum + f(b));

    printf("The value of the integral is: %.4f\n", integral);
    return 0;
}
