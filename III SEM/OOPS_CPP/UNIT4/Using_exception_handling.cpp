#include <iostream>
#include <stdexcept>
using namespace std;
class calculate{
    double d1, d2;
    public:
    void getdata(double x, double y){
        d1 = x;
        d2 = y;
    }
    void division(){
        
        if (d2 == 0) { 
        throw runtime_error("Math error: Attempted to divide by Zero\n"); 
    }
        double d = d1 / d2;
        cout << "division of " << d1 << " by " << d2 << " is " << d << endl;
    }
};
int main(){
    calculate ex;
    ex.getdata(30, 2);
     // try block calls the Division function 
    try { 
        ex.division();
  
       /* // this will not print in this example 
        cout << "The quotient is "
             << result << endl; */
    } 
  
    // catch block catches exception thrown 
    // by the Division function 
    catch (runtime_error& e) { 
  
        // prints that exception has occurred 
        // calls the what function 
        // using runtime_error object 
        cout << "Exception occurred" << endl 
             << e.what(); 
    } 
    return 0;
}