#include <stdio.h>
void TOH(char s, char d, char a, int n)
{
    if (n == 1)
    {
        printf("%c -> %c\n", s, d);
        return;
    }
    TOH(s, a, d, n - 1);
    printf("%c -> %c\n", s, d);
    TOH(a, d, s, n - 1);
}
int main()
{
    int n;
    printf("Enter No of Disk\n");
    scanf("%d", &n);
    TOH('A', 'C', 'B', n);
    return 0;
}