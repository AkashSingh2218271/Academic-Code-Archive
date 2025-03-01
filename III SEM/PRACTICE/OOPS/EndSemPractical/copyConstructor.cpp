#include <iostream>
using namespace std;

class copycons{
    int a, m;
    public:
    copycons(int m1, int a1) : a(m1), m(a1) {}
    copycons(const copycons& obj) : a(obj.a), m(obj.m) {}
    void putData(){
        cout << "value of a is " << a << " value of m is " << m << endl;
    }     
};

int main(){
    copycons ma(143, 7), am(ma);
    ma.putData();
    am.putData();

    return 0;
}