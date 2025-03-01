#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
void swap(int *a, int *b) {
    if (a == b)
    {
        return;
    }
    *a = (*a) + (*b);
    *b = (*a) - (*b);
    *a = (*a) - (*b);
}

// void inputArr(int arr[], int n) {
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
// }

// void printArr(int arr[], int n) {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int s = lb;
    int e = ub;
    while (s < e)
    {
        while (arr[s] <= pivot)
        {
            s++;
        }
        while (arr[e] > pivot)
        {
            e--;
        }
        if (s < e)
        {
            swap(&arr[s], &arr[e]);
        }        
    }
    swap(&arr[lb], &arr[e]);

    return e;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}
int random(int arr[], int lb, int ub) {
    int r = lb + rand()%(ub - lb);
    swap(&arr[r], &arr[0]);
    return partition(arr, lb, ub);
}
void quickSortRandom(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = random(arr, lb, ub); 
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter element of array : ");
    inputArr(arr, n);
    printf("Array before sorting : ");
    printArr(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Array after sorting : ");
    printArr(arr, n);

    return 0;
}