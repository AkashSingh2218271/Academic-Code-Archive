#include <iostream>
using namespace std;
void Input_Matrices(int arr[3][3])
{
    printf("Enter a matrices\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void Multiply_Matrices(int arr[3][3], int arr1[3][3])
{
    int ans[3][3];
    int x = 0;
    int y = 1;
    int z = 2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = arr[i][x] * arr1[x][j] + arr[i][y] * arr1[y][j] + arr[i][z] * arr1[z][j];
        }
    }
    printf("New Matrix after multiplication ->\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3], arr1[3][3];
    Input_Matrices(arr);
    Input_Matrices(arr1);
    Multiply_Matrices(arr, arr1);
    return 0;
}
