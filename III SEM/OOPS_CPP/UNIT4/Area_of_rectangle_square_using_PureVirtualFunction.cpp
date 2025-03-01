#include <iostream>
using namespace std;
class Area {
    protected:
        float a, b, s;
        public:
        virtual float Areafun() = 0;
        Area(float x, float y, float z) : a(x), b(y), s(z) {}
};
class rectangle: public Area{
    public:
        rectangle(float l, float br): Area(l, br, 0) {}
        float Areafun(){
            return a * b;
        }
};
class square: public Area{
    public:
        square(float side): Area(0, 0, side) {}
        float Areafun(){
            return s * s;
        }
};
int main(){
    rectangle r(10, 4);
    square s(5);
    Area *basePtr;
    basePtr = &r;
    cout << "Area of Rectangle " << basePtr->Areafun() << endl;
    basePtr = &s;
    cout << "Area of Square " << basePtr->Areafun() << endl;
    return 0;
}