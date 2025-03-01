#include <stdio.h>
// todo array representation of sparse matrices using user defined function --<>
// ~ print 2D array --<>
void print(int r, int c, int arr[r][c])
{
    printf("matrix is -->>\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d", arr[i][j]);
        }
    printf("\n");
    }
}
// info function for array representation of sparse matrices --<>
void sparse_matrices(int r, int c, int x, int arr[r][c])
{
    int ans[3][x], k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] != 0)
            {
                ans[0][k] = i;
                ans[1][k] = j;
                ans[2][k] = arr[i][j];
                k++;
            }
        }
    }
    print(3, x, ans);
}
int main()
{
    static int r, c, x = 0;
    printf("Enter row and column for a matrix respectively -->>\n");
    scanf("%d %d", &r, &c);
    printf("Enter element in 2d array -->> \n");
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0)
            {
                x++;
            }
        }
    }
    print(r, c, arr);
    sparse_matrices(r, c, x, arr);
    return 0;
}