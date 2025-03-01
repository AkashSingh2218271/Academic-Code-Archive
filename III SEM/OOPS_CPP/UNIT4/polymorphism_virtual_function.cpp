#include <iostream>
using namespace std;

class Base_class {
public:
    int x;
    int y;
    Base_class(int a, int b): x(a), y(b) {}

    virtual void display() {
        cout << "x = " << x << " " << "y = " << y << endl;
    }
};

class derived_class: public Base_class {
public:
    int z;
    derived_class(int n): Base_class(0,0) {
        z = n;
    }

    void display() {
        cout << "z = " << z << endl;
    }
};

int main() {
    Base_class b(5, 10);
    Base_class *base_class_ptr;
    derived_class d(20);
    base_class_ptr = &b;
    base_class_ptr->display();
    base_class_ptr = &d;
    base_class_ptr->display();
    return 0; 
}
