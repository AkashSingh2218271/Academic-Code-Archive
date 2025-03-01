#include <stdio.h>
#include <math.h>

float valueOfEq(float x) {
    return x - cos(x);
}

void bijection(float x1, float x2, int maxItr) {
    int i = 0;
    float root = (x1 + x2) / 2;
    printf("value in itr %d is %f\n", i+1, root);
    while (i < maxItr - 1)
    {
        if (valueOfEq(root) < 0)
        {
            x1 = root;
        } else {
            x2 = root;
        }
        root = (x1 + x2) / 2;
        printf("value in itr %d is %f\n", i+2, root);
        i++;
    }
    printf("Roots of equation(x - cos(x)) is %f", root);
}

int main() {
    float a = 0, b = 1;
    int m;
    while (1)
    {
        if (valueOfEq(a) < 0 && valueOfEq(b) > 0)
        {
            break;
        }
        a = a + 1;
        b = b + 1;
    }
    printf("Enter max iteration ");
    scanf("%d", &m);
    bijection(a, b, m);

    return 0;
}