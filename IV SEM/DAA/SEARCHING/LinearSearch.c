#include <stdio.h>

void linearSearch(int arr[], int n, int key)
{
    int count = 0, i = 0, flag = 0;
    for (; i < n; i++)
    {
        count++;
        if (arr[i] == key)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        printf("Element is present at index %d\n", i);
    }
    else
    {
        printf("Element is not present\n");
    }
    printf("Number of comparision are %d\n", count);
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
    int n, x, key, i = 0;
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
        linearSearch(arr, n, key);
        i++;
    }

    return 0;
}