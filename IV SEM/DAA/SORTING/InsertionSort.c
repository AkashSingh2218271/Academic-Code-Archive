#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
           arr[j + 1] = arr[j];
           j--;
        }
        arr[j + 1] = temp;
    }
}

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], int n) {
    for (int  i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter element of array : ");
    inputArr(arr, n);
    printf("Array before sorting is ");
    printArr(arr, n);
    insertionSort(arr, n);
    printf("Array after sorting is ");
    printArr(arr, n);
    return 0;
}