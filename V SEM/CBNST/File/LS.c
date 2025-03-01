#include <stdio.h>

int main() {
    int n, i;
    float x[100], y[100], sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, a, b;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");
    for(i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i + 1);
        scanf("%f", &y[i]);

        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    b = (sumY - a * sumX) / n;

    printf("The equation of the line is: y = %.4fx + %.4f\n", a, b);

    return 0;
}
