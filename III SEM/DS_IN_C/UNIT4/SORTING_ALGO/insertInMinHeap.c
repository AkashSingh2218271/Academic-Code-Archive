#include <stdio.h>

// Function to heapify a subtree rooted with the given node
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is smaller than the root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // Check if right child is smaller than the smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If the smallest is not the root, then swap and heapify the affected subtree
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

// Function to insert a new element into the heap
void insertHeap(int arr[], int *n, int key) {
    // Increase the heap size and insert the new element at the end
    (*n)++;
    int i = *n - 1;
    arr[i] = key;

    // Fix the min-heap property if it is violated
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
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
