#include <iostream>
using namespace std;

class Sum
{
    int x;
    int y;
    int sum;
    int z;

public:
    void get_value(int a, int b);
    // ! constant member function within the class
    void put_value() const
    {
        cout << "value of x is : " << x << endl;
        cout << "value of y is : " << y << endl;
        cout << "sum of x and y is : " << sum << endl;
    }
};
void Sum ::get_value(int a, int b)
{
    x = a;
    y = b;
    sum = a + b;
}
int main()
{
    Sum m;
    m.get_value(5, 7);
    m.put_value();
    return 0;
}