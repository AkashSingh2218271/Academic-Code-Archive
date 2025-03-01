#include <iostream>
using namespace std;
void PrintArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] << " ";
    }
    cout << endl;
}
void RotateArr(int arr[], int n) {
    int i, j;
    i = 0;
    j = n - 1;
    while(i < j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++;
        j--;
    }
}
int main() {
    int n;
    int arr[] = {1, 2, 3, 4, 5};
    n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before rotation" << endl;
    PrintArr(arr, n);
    RotateArr(arr, n);
    cout << "Array after rotation" << endl;
    PrintArr(arr, n);
    return 0;
}