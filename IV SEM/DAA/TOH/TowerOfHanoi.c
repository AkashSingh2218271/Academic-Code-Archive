#include <stdio.h>

void toh(int n, char s, char d, char a) {
    if(n == 1) 
    {
        printf("%c->%c\n", s, d);
        return;
    }
    toh(n - 1, s, a, d);
    printf("%c->%c\n", s, d);
    toh(n - 1, a, d, s);
}
int main() {
    int n;
    printf("Enter number of disk : ");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}
