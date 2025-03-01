#include <stdio.h>

float f(float x, float y) {
    return x + y;  // Example ODE: dy/dx = x + y
}

int main() {
    float x0, y0, x, y, h;
    int n, i;

    printf("Enter initial value x0: ");
    scanf("%f", &x0);
    printf("Enter initial value y0: ");
    scanf("%f", &y0);
    printf("Enter the step size h: ");
    scanf("%f", &h);
    printf("Enter the number of steps n: ");
    scanf("%d", &n);

    x = x0;
    y = y0;

    printf("x0 = %.4f, y0 = %.4f\n", x, y);
    for(i = 1; i <= n; i++) {
        y = y + h * f(x, y);
        x = x + h;
        printf("x = %.4f, y = %.4f\n", x, y);
    }

    return 0;
}
