#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j;
    float x[10], y[10], u, result, term;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &u);

    result = 0.0;
    for (i = 0; i < n; i++) {
        term = 1.0;
        for (j = 0; j < n; j++) {
            if (j != i) {
                term *= (u - x[j]) / (x[i] - x[j]);
            }
        }
        result += term * y[i];
    }

    printf("The interpolated value at %.2f is %.3f\n", u, result);
    return 0;
}
