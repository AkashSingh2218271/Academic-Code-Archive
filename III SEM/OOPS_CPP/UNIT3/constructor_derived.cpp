#include <iostream>
using namespace std;

class A{
    int a,b;
    public:
        A(int x, int y) : a(x), b(y) {}

        void display(){
            cout<<a<<" "<<b<<endl;
        }
};

class B:public A{
    int c;
    public:
        B(int x, int y, int z) : A(x,y), c(z) {}
        void display2(){
            display();
            cout<<" "<<c;
        }
};

int main(){
    B x(23,34,45);
    x.display2();
}   