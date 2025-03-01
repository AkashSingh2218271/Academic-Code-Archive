#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool binary_search(int arr[], int n, int key){
    int s = 0;
    int e = n - 1;
    bool flag = false;
    while (s <= e)
    {
        int mid = s + (e - s)/2;
        if (arr[mid] == key)
        {
            flag = true;
            break;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;        
        }else
        {
            e = mid - 1;
        }   
    }
    return flag; 
}
int main(){
    int arr[5];
    int key;
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("n = %d\n", n);
    printf("Enter an arrays elements.\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter key to search.\n");
    scanf("%d", &key);
    if(binary_search(arr, n, key)){
        printf("Element found.\n");
    }else
    {
        printf("Element not found.\n");
    }
    return 0;
}