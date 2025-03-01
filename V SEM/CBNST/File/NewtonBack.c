#include <stdio.h>

int main() {
    int n, i, j;
    float x[10], y[10], diffTable[10][10], u, h, result, term;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }

    for (i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    for (j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
        }
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &u);

    h = x[1] - x[0];
    float p = (u - x[n - 1]) / h;

    result = diffTable[n - 1][0];
    term = 1.0;

    for (i = 1; i < n; i++) {
        term *= (p + i - 1) / i;
        result += term * diffTable[n - 1][i];
    }

    printf("The interpolated value at %.2f is %.3f\n", u, result);
    return 0;
}
