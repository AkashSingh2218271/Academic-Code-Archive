#include <stdio.h>

int fib(int n) {
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter value of n : ");
    scanf("%d", &n);
    printf("%d th term of fibonacci is %d", n, fib(n-1));
    return 0;
}