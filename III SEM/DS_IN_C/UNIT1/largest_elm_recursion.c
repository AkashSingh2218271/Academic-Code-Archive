#include <stdio.h>
#include <math.h>
int Largest(int arr[], int n, int l) {
    if (n == 0)
    {
        return l;
    }
    l = fmax(arr[n-1], l);
    return Largest(arr, n-1, l);
}
int largest(int arr[], int n) {
    if (n == 1)
    {
        return arr[0];
    }
    return fmax(largest(arr, n-1), arr[n-1]);
} 
int main() {
    int arr[10] = {1, 3, 4, 7, 5};
    int n, l = 0;
    n = sizeof(arr)/sizeof(arr[0]);
    printf("Largest element in array is = %d\n", Largest(arr, n, l));
    printf("Largest element in array is = %d\n", largest(arr, n));
    return 0;
}
/*
! approch two --<>
int find_element(int arr[M], int m)
{
    if (m == 1)
    {
        return arr[0];
    }
    return fmax(find_element(arr, m-1), arr[m-1]);
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
    printf("largest element in array is -->> %d\n", find_element(arr, m));
    for (int i = 0; i < M; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
*/