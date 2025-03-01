#include <stdio.h>
#include <string.h>
# define M 5
int top = -1;
char stack[M];
void push() {
    if (top == M-1)
    {
        printf("stack overflow");
    }
    printf("Enter a string -->>\n");
    for(top = 0; top < M; top++)
    {
        scanf("%c", &stack[top]);
        fflush(stdin);
    }
    top--;
}
char pop()
{
    if (top == -1)
    {
        printf("string is empty.\n");
    }
    return stack[top--];
}
void display() {
    int i = 0;
    printf("Reverse stack is ->\n");
    while (i < M)
    {
        printf("%c ", pop());
        i++;
    }
}
int main() {
    push();
    display();
    return 0;
}