#include <iostream>
using namespace std;
class B;
class A{
    int x;
    public:
    void getData(){
        cout << "Enter value of x :" << endl;
        cin >> x;
    }
    void putData(){
        cout << "Value of x is : " << x << endl;
    }
    friend void sum(A, B);
};

class B{
    int y;
    public:
    void get_Data(){
        cout << "Enter value of y :" << endl;
        cin >> y;
    }
    void put_Data(){
        cout << "Value of y is : " << y << endl;
    }
    friend void sum(A, B);
};

void sum(A ox, B oy){
    cout << "Addition of " << ox.x << " and " << oy.y << " is : " << ox.x + oy.y << endl;
}

int main(){
    A a;
    B b;
    a.getData();
    b.get_Data();
    a.putData();
    b.put_Data();
    sum(a, b);

    return 0;
}