#include <stdio.h>
int Partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int t = a[start];
            a[start] = a[end];
            a[end] = t;
        }
    }
    int t = a[end];
    a[end] = a[lb];
    a[lb] = t;
    return end;
}
void QuickSort(int a[], int lb, int ub){
    if(lb < ub)
    {
      int loc = Partition(a, lb, ub);
      QuickSort(a, lb, loc - 1);
      QuickSort(a, loc + 1, ub);  
    }
}
void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }   
}
int main()
{
    int a[7];
    printf("Input array element:\n");
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &a[i]);
    }
    int n = sizeof(a)/sizeof(a[0]);
    QuickSort(a, 0, n - 1);
    printArr(a, n);
}