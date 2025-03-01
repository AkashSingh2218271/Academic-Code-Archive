#include <stdio.h>

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (i != smallest) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

void HeapSort(int arr[], int n) {
    // Build heap
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    // Deletion in heap
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        minHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform Heap Sort
    HeapSort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
