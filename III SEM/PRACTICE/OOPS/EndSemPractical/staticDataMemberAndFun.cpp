#include <iostream>
using namespace std;

class staticMandF
{
    static int x;

public:
    void update()
    {
        x++;
    }
    void putData(){
        cout << "Value of x is " << x << endl;
    }
    static int square(){
        return x * x;
    }
};

int staticMandF::x;

int main()
{
    staticMandF s;
    s.update();
    s.update();
    s.putData();
    cout << "Square is " << staticMandF::square() << endl;

    return 0;
}