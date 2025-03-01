#include <iostream>
using namespace std;

class cons{
    int x;
    public:
    cons(){
        x = 5;
    }
    void putData(){
        cout << "value of x is " << x << endl;
    }
};

int main(){
    cons * obj = new cons();
    obj->putData();

    return 0;
}