#include <stdio.h>
#include "Util.h"


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

void merge(int arr[], int lb, int mid, int ub, int ans[]) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
           ans[k] = arr[i];
           i++;
        } else {
            ans[k] = arr[j];
            j++; 
        }
        k++;
    }
    while (i <= mid)
    {
        ans[k] = arr[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        ans[k] = arr[j];
        j++;
        k++;
    }
    for (int i = lb; i <= ub; i++)
    {
        printf("ans = %d ", ans[i]);
        arr[i] = ans[i];
    } printf("\n");
}
void mergeSort(int arr[], int lb, int ub, int ans[]) {
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        mergeSort(arr, lb, mid, ans);
        mergeSort(arr, mid + 1, ub, ans);
        merge(arr, lb, mid, ub, ans);
    }
}
int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n], ans[n];
    printf("Enter elements of array : ");
    inputArr(arr, n);
    printf("Array before sorting : ");
    printArr(arr, n);
    mergeSort(arr, 0, n - 1, ans);
    printf("Array after sorting : ");
    printArr(arr, n);
    return 0;
}
