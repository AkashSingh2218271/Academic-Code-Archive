#include <stdio.h>
int total_chocolate(int ch, int w, int r)
{
    if (w == 0)
    {
        return ch;
    }

    // printf("w = %d\n", w);
    // printf("r = %d\n", r);
    // ch += (w + r);
    printf("ch = %d\n", ch);
    total_chocolate(ch + w + r, w / 2, w % 2);
}
int main()
{
    int M, P;
    printf("Enter money you have\n");
    scanf("%d", &M);
    printf("Enter price  of each chocolate\n");
    scanf("%d", &P);
    int ch = M / P;
    // printf("ch = %d", ch);
    printf("Total chocolate are -> %d", total_chocolate(0, ch, 0));
    return 0;
}