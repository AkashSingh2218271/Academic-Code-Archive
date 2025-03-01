#include <stdio.h>
void Merge(int a[], int lb, int mid, int ub, int ans[])
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            ans[k] = a[i];
            i++;
        }
        else
        {
            ans[k] = a[j];
            j++;
        }
        k++;
    }
        while (j <= ub)
        {
            ans[k] = a[j];
            j++;
            k++;
        }
        while (i <= mid)
        {
            ans[k] = a[i];
            i++;
            k++;
        }
    for (int i = lb; i <= ub; i++)
    {
        a[i] = ans[i];
    }
}
void MergeSort(int a[], int lb, int ub, int ans[])
{
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        MergeSort(a, lb, mid, ans);
        MergeSort(a, mid + 1, ub, ans);
        Merge(a, lb, mid, ub, ans);
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int a[n], ans[n];
    printf("Input array element : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    //int n = sizeof(a) / sizeof(a[0]);
    MergeSort(a, 0, n - 1, ans);
    printf("Sorted array:\n");
    printArr(a, n);
    return 0;
}