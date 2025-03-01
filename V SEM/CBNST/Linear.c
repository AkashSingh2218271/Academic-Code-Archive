#include <stdio.h>

void parabolicCurveFitting(int n, double x[], double y[], double *a, double *b, double *c) {
    double sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    double sumY = 0, sumXY = 0, sumX2Y = 0;
    
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }

    double matrix[3][4] = {
        {n, sumX, sumX2, sumY},
        {sumX, sumX2, sumX3, sumXY},
        {sumX2, sumX3, sumX4, sumX2Y}
    };

    // Gaussian elimination to solve for a, b, c
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < 4; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    // Back substitution
    *c = matrix[2][3] / matrix[2][2];
    *b = (matrix[1][3] - matrix[1][2] * (*c)) / matrix[1][1];
    *a = (matrix[0][3] - matrix[0][2] * (*c) - matrix[0][1] * (*b)) / matrix[0][0];
}

int main() {
    int n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d - x: ", i + 1);
        scanf("%lf", &x[i]);
        printf("Point %d - y: ", i + 1);
        scanf("%lf", &y[i]);
    }

    double a, b, c;
    parabolicCurveFitting(n, x, y, &a, &b, &c);

    printf("The equation of the parabola is: y = %.4lfx^2 + %.4lfx + %.4lf\n", a, b, c);

    return 0;
}
