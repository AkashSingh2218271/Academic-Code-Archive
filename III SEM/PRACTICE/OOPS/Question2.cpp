#include <iostream>
using namespace std;

class A
{
private:
    int x;
public:
    A(){
        x = 5;
    }
    friend A operator++(A& obj1, int);
    friend A operator--(A& obj2, int);
    // ? ~A();
};
A operator++(A& obj1, int) {
    A temp = obj1;
    obj1.x++;
    cout<< "value of x : " << obj1.x << endl;
    return temp;
}
A operator--(A& obj2, int) {
    A temp = obj2;
    obj2.x--;
    cout<< "value of x is : " << obj2.x << endl;
    return temp;
}
int main(){
    A obj1, obj2;
    obj1++;
    obj2--;
    return 0;
}

/*
class A
{
private:
    int x;
public:
    A(){
        x = 5;
    }
    // Change the return type to A
    friend A operator++(A& obj, int);
    friend A operator--(A& obj2, int);
};

// Define the friend functions outside the class
// Create a temporary object to store the original value
// Increment or decrement the object's value
// Return the temporary object
A operator++(A& obj, int) {
    A temp = obj;
    obj.x++;
    cout<< "value of x : " << obj.x << endl;
    return temp;
}
A operator--(A& obj2, int) {
    A temp = obj2;
    obj2.x--;
    cout<< "value of x is : " << obj2.x << endl;
    return temp;
}
int main(){
    A obj, obj2;
    obj++;
    obj2--;
    return 0;
}
*/