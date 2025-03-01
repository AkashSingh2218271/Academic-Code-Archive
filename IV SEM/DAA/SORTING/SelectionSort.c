#include <stdio.h>

void swap(int *a, int *b) {
    if (a == b)
    {
        return;
    }
    *a = (*a) + (*b);
    *b = (*a) - (*b);
    *a = (*a) - (*b);
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;    
            }
        }
        if (i != min)
        {
            swap(&arr[i], &arr[min]);
        }
    }
}

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
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
    printf("Array element before sorting is ");
    printArr(arr, n);
    selectionSort(arr, n);
    printf("Array element after sorting is ");
    printArr(arr, n);

    return 0;
}