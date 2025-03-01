#include <stdio.h>

float f(float x, float y) {
    return x + y;  // Example ODE: dy/dx = x + y
}

int main() {
    float x0, y0, x, y, h, k1, k2, k3, k4;
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
        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h, y + k3);
        
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;
        
        printf("x = %.4f, y = %.4f\n", x, y);
    }

    return 0;
}
