#include <iostream>
#include <string>
using namespace std;
class Parent{
    int x;
    protected:
    string name_p;
    public :
    int v = 7;
    Parent(){
        x = 5;
    }
    void putval();
};
void Parent::putval(){
    cout << "x = " << x << endl;
}
class girl : public Parent{
    int y;
    public:
    girl(){
        y = 10;
    }
    void putdata(){
        cout << "y = " << y << endl;
        cout << v << endl;
    }
};
class boy : public Parent{
    int z;
    public :
    boy(){
        z = 2;
    }
    void display(){
        cout << "z = " << z << endl;
    }
}; 
class son: protected Parent{
    string name_s;
    public:
    void set_name(string pn, string sn){
        name_s = sn;
        name_p = pn;
    }
    void put_name(){
        cout << "pname = " << name_p << endl;
        cout << "sname = " << name_s << endl;
    }
}; 
int main(){
    girl g;
    boy b;
    son s;
    g.putdata();
    g.putval();
    b.display();
    b.putval();
    s.set_name("Akash", "pawan");
    s.put_name();
    return 0;
}