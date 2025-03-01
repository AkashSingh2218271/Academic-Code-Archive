#include <iostream>
using namespace std;

class parameterizedcons{
    int a, y;
    public:
    parameterizedcons(int m, int n){
        a = m;
        y = n;
    }
    void putData();
};
void parameterizedcons::putData(){
    cout << "value of a is " << a << " and value of y is " << y << endl;
}
int main(){
    parameterizedcons ma(143, 2);
    ma.putData();

    return 0;
}