#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swapTwo(int *a, int *b) {
    int x = (*a);
    (*a) = (*b);
    (*b) = x;
}
void bubbleSort(int arr[], int n) {
    bool f;
    for (int i = 0; i < n - 1; i++)
    {
        f = false;
        for (int j = 0; j < n - i -1; j++)
        {
            if(arr[j] > arr[j+1]){
                swapTwo(&arr[j], &arr[j+1]);
                f = true;
            }
        }
        if (!f)
        {
            break;
        }
    }   
}
void binarySearch(int arr[], int n, int key) {
    int flag = 0, mid, s = 0, e, count = 0;
    bool b = false;
    e = n-1;
    mid = s + (e - s)/2;
    while (s <= e) {
        mid = s + (e - s)/2;
        count++;
        if(arr[mid] == key) {
            b = true;
            break;
        } else if (arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    if (b)
    {
        printf("Element is present at index %d\n", mid);
    } else {
        printf("Element is not present\n");
    }
    printf("Number of comparision are %d\n", count);
}

void inputArr(int arr[], int n) {
    printf("Enter the elements in array :\n");
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

int main() {
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
        printf("Array before sorting \n");
        printArr(arr, n);
        bubbleSort(arr, n);
        printf("Array after sorting \n");
        printArr(arr, n);
        binarySearch(arr, n, key);
        i++;
    }

    return 0;
}