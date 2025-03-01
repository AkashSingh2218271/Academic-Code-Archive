#include <stdio.h>

// Function to heapify a subtree rooted with the given node
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, then swap and heapify the affected subtree
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Function to insert a new element into the heap
void insertHeap(int arr[], int *n, int key) {
    // Increase the heap size and insert the new element at the end
    (*n)++;
    int i = *n - 1;
    arr[i] = key;

    // Fix the max-heap property if it is violated
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Function to print the elements of the heap
void printHeap(int arr[], int n) {
    printf("Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int heap[100];  // Assuming a maximum heap size of 100
    int heapSize = 0;

    // Input elements
    int input[] = {56, 25, 102, 52, 2, 45, 1};
    int inputSize = sizeof(input) / sizeof(input[0]);

    // Insert elements into the heap
    for (int i = 0; i < inputSize; i++) {
        insertHeap(heap, &heapSize, input[i]);
        printHeap(heap, heapSize);
    }

    return 0;
}
