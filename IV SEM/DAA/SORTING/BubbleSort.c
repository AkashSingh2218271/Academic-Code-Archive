#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    *a = (*a) + (*b);
    *b = (*a) - (*b);
    *a = (*a) - (*b);
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
            
        }   
    }
}

void bubbleSortOptimized(int arr[], int n) {
    bool flag; 
    for (int i = 0; i < n-1; i++)
    {
        flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                flag = true;
            }
        }
        if(!flag) {
            break;
        }   
    }
}

void inputArr(int arr[], int n) {
    printf("Enter elements of array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    inputArr(arr, n);
    printf("Array before sorting is ");
    printArr(arr, n);
    bubbleSort(arr, n);
    printf("Array after bubble sorting is ");
    printArr(arr, n);
    bubbleSortOptimized(arr, n);
    printf("Array after optimized bubble sorting is ");
    printArr(arr, n);
    return 0;
}