#include<stdio.h>
void insertionSort(int arr[], int n){
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
    printf("\nArray after sorting: ");
    
}
void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }   
}
int main(){
    int arr[5];
    printf("Enter array elements:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting: ");
    printArr(arr, n);
    insertionSort(arr, n);
    printArr(arr, n);
    return 0;
}