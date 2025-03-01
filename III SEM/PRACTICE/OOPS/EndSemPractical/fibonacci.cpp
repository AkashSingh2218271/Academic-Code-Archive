#include <iostream>
using namespace std;

//! using for loop
void fib(int n)
{
    int t1 = 0, t2 = 1, nextTerm = 0;
    nextTerm = t1 + t2;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == 1)
        {
            cout << i;
        }
        else
        {
            cout << nextTerm;
            t1 = t2;
            t2 = nextTerm;
            nextTerm = t1 + t2;
        }
    }
}

void fib1(int n)
{
    int a = 0, b = 1;
    cout << "1 fibonacci series is : ";
    for (int i = 0; i < n; i++)
    {
        int sum = a + b;
        cout << a;
        b = a;
        a = sum;
    }
}

//~ using recursion and memoization
int fibSeries(int n, int dp[])
{
    int f = 1;
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    f = fibSeries(n - 1, dp) + fibSeries(n - 2, dp);
    return f;
}

int main()
{
    int n;
    cout << "Enter a num upto where you want to print series" << endl;
    cin >> n;
    int dp[n] = {0};
    cout << endl;

    fib1(n);
    cout << endl;

    cout << "(for loop)fibonacci series : ";
    fib(n);
    cout << endl;

    cout << "(recursion)fibonacci series : ";
    for (int i = 0; i < n; i++)
    {
        cout << fibSeries(i, dp);
    }

    return 0;
}