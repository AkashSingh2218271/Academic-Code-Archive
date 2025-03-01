#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// todo /* LINEAR SEARCHING IN C */
bool linearSearch(int x){
    int arr[5];
    bool b = false;
    printf("Enter elements in array.\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] == x){
            b = true;
        }
    }
    return b;
}
int main(){
    int x;
    printf("Enter an element to search.\n");
    scanf("%d", &x);
    if(linearSearch(x)){
        printf("found.\n");
    }
    else
    {
        printf("Not found.\n");
    }   
    return 0;
}