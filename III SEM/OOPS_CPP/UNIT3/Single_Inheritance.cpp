#include <iostream>
using namespace std;
class A{
    int x;
    public:
        A(){
            x = 2;
            cout << "x = " << x << endl;
        }
};
class B: public A{
    int y;
    public:
        B(){
            y = 5;
           cout << "Y =" << y << endl;
        }
};
int main()
{
    B b;
    return 0;
}