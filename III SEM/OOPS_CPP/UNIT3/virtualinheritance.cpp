#include <iostream>
using namespace std;
class S
{
public:
    int s = 1;
};
class B : virtual public S
{
public:
    int b = 2;
};
class C : virtual public S
{
public:
    int c = 3;
};
class D : public C, public B
{
public:
    int d = 4;
};
int main()
{
    D d1;
    cout << d1.s << endl;
    cout << d1.b << endl;
    cout << d1.c << endl;
    cout << d1.d << endl;
}