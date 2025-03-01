#include <stdio.h>
#include <math.h>

float valueOfEq(float x) {
    return (x * x * x) - x - 11;
}

void regulaFalsi(float x1, float x2, int maxItr) {
    int i = 0;
    float f1 = valueOfEq(x1);
    float f2 = valueOfEq(x2);
    float root;

    if (f1 * f2 >= 0) {
        printf("The initial guesses do not bracket the root.\n");
        return;
    }

    while (i < maxItr) {
        root = (x1 * f2 - x2 * f1) / (f2 - f1);
        float fRoot = valueOfEq(root);

        printf("Value in iteration %d is %f\n", i+1, root);

        if (fabs(valueOfEq(root)) <= 0.0001 || fabs(x2 - x1) <= 0.0001) {
            break;
        }

        if (f1 * fRoot < 0) {
            x2 = root;
            f2 = fRoot;
        } else {
            x1 = root;
            f1 = fRoot;
        }

        i++;
    }

    printf("Root of equation (x^3 - x - 11) is %f\n", root);
}

int main() {
    float a = 0, b = 1;
    int m;

    while (1) {
        if (valueOfEq(a) * valueOfEq(b) < 0) {
            break;
        }
        a += 1;
        b += 1;
    }

    printf("Enter max iteration: ");
    scanf("%d", &m);

    regulaFalsi(a, b, m);

    return 0;
}
