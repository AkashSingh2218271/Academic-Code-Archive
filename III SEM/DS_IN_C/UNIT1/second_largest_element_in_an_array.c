#include <stdio.h>
#include <math.h>
#define M 5
// todo find second largest element in an array --<>
// info function to calculate second largest element --<>
int find_element(int arr[M], int m)
{
    int s, l;
    s = l = -1;
    for (int i = 0; i < M; i++)
    {
        if (arr[i] > l)
        {
            s = l;
            l = arr[i];
        }
        else if (arr[i] > s)
        {
            s = arr[i];
        }
    }
    return s;
}
int main()
{
    int arr[M];
    for (int i = 0; i < M; i++)
    {
        printf("Enter element for index %d\n", i);
        scanf("%d", &arr[i]);
    }
    int m = sizeof(arr) / sizeof(arr[0]);
    printf("Second largest element in array is -->> %d\n", find_element(arr, m));
    /*for (int i = 0; i < M; i++)
    {
        printf("%d\n", arr[i]);
    } */
    return 0;
}