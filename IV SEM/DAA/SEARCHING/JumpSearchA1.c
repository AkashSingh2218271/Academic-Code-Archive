#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void swapTwo(int *a, int *b) {
    int x = (*a);
    (*a) = (*b);
    (*b) = x;
}

void bubbleSort(int arr[], int n) {
    bool f;
    for (int i = 0; i < n - 1; i++)
    {
        f = false;
        for (int j = 0; j < n - i -1; j++)
        {
            if(arr[j] > arr[j+1]){
                swapTwo(&arr[j], &arr[j+1]);
                f = true;
            }
        }
        if (!f)
        {
            break;
        }
    }   
}
int jumpSearch(int arr[], int n, int key) {
    int m = sqrt(n);
    int z = fmin(m, n);
    while (arr[z- 1] < n)
    {
        int i = m;
        m += sqrt(n);
        if(i >= n) {
            return -1;
        }
        while (arr[i] < key)
        {
            i++;
            if (i == fmin(m,n))
            {
                return -1;
            }
            
        }
        if (arr[i] == key)
        {
            return i;
        }
        z = fmin(m, n);
    }
    return -1;
}

void inputArr(int arr[], int n) {
    printf("Enter array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, x, idx, key, i = 0;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
   
    printf("Enter the number array you want to check for : ");
    scanf("%d", &x);
    while (i < x)
    {
        inputArr(arr, n);
        printf("Enter a element you want to search : ");
        scanf("%d", &key);
        printf("Array before sorting : ");
        printArr(arr, n);
        bubbleSort(arr, n);
        printf("Array after sorting : ");
        printArr(arr, n);
        idx = jumpSearch(arr, n, key);
        printf("idx = %d", idx);
        i++;
    }
    

    return 0;
}