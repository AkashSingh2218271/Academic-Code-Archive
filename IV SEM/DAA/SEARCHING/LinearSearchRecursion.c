#include <stdio.h>

int linearSearchRecursive(int arr[], int n, int key)
{
    if (n < 0)
    {
        return n;
    }
    if (arr[n] == key)
    {
        return n;
    }
    return linearSearchRecursive(arr, --n, key);
}

void inputArr(int arr[], int n)
{
    printf("Enter element in array :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], int n)
{
    printf("Input array is : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, x, key, i = 0, idx;
    printf("Enter the size of arr : ");
    scanf("%d", &n);
    printf("Enter the number of array you want to check :");
    scanf("%d", &x);
    int arr[n];
    while (i < x)
    {
        inputArr(arr, n);
        printf("Enter key to search in array : ");
        scanf("%d", &key);
        printArr(arr, n);
        idx = linearSearchRecursive(arr, n - 1, key);
        if (idx != -1)
        {
            printf("Element is present at index %d\n", idx);
            printf("Number of comparision are %d\n", idx + 1);
        }
        else
        {
            printf("Element is not present\n");
            printf("Number of comparision are %d\n", n);
        }
        i++;
    }
    return 0;
}