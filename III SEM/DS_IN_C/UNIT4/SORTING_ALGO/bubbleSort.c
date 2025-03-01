#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1]){
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }
    printf("\nArray after bubble sort : ");
}
void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }   
}
int main(){
    int arr[5];
    printf("Enter array elements: \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    int n = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, n);
    bubbleSort(arr, n);
    printArr(arr, n);
    return 0;
}