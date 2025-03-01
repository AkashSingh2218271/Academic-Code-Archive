#include <iostream>
#include <cmath>
using namespace std;
class base_shapes{
    protected:
        float b, h;
        float r;
    public:
    virtual float area() = 0;
    base_shapes(int x, int y, int z) : b(x), h(y), r(z) {} 
};
class Triangle: public base_shapes{
    public:
    Triangle(int ba, int ht): base_shapes(ba, ht, 0) {}
    float area(){
        return 0.5 * b * h;
    }
};
class Circle: public base_shapes{
    public:
    Circle(int rd): base_shapes(0, 0, rd) {}
    float area(){
        return M_PI * r *r; 
    }
};
int main(){
    Circle cr(7);
    Triangle t(4, 10);
    base_shapes *base_ptr;
    base_ptr = &cr;
    float ans = base_ptr->area();
    cout << "area of circle " << ans << endl;
    base_ptr = &t;
    float ans1 = base_ptr->area();
    cout << "area of triangle " << ans1 << endl;
    return 0;
}