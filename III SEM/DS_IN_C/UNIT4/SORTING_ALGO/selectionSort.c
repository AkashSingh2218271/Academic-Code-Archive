#include <stdio.h>

void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }   
        }
        if(min != i){
            int t = arr[i];
            arr[i] = arr[min];
            arr[min] = t;
        }
    } 
}
void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }   
}
int main(){
    int arr[5];
    printf("Input Array :\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Array after sorting : ");
    printArr(arr, n);
    return 0;
}