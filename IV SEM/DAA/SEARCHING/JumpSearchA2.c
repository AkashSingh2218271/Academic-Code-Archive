#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int key) {
    int low, m = sqrt(n);
    for (int i = 0; i < n; i += m)
    {
        if(arr[i] == key) {
            return i;
        }
        if(arr[i] < key) {
            low = i;
        }
        if(arr[i] > key) {
            break;        
        }
    }
    for (int i = low; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
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
    int n, idx, key;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    inputArr(arr, n);
    printf("Enter element you want to search : ");
    scanf("%d", &key);
    printf("Array before sorting is ");
    printArr(arr, n);

    printf("Array after sorting is ");
    printArr(arr, n);
    idx = jumpSearch(arr, n, key);
    if(idx == -1) {
        printf("%d is not present", key);
    } else {
        printf("%d is present at index %d", key, idx);
    }
    return 0;
}