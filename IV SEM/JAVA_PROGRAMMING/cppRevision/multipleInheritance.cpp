#include <iostream>
#include <string>
using namespace std;
class Student {
	private:
		string name;
		int rollNum;
		string address;
		long pNum;
	public:
		void getVal() {
			cout << "Enter your name : ";
            cin >> name;
            cout << "Enter your roll number : ";
            cin >> rollNum;
            cout << "Enter your address : ";
            cin >> address;
            cout << "Enter your phone number : ";
            cin >> pNum ;
		}
		void displayVal(){
			cout << "Name is : " << name << endl;
			cout << "Roll number is : " << rollNum << endl;
			cout << "Address is : " << address << endl;
			cout << "Phone number is : " << pNum << endl;
		}
	
};
class Marks {
	private:
		int p,c,m;
        float Avg;
	public:
        void calAvg() {
            Avg = 0;
            Avg = (p+m+c/3);
            if(Avg >= 75) {
				cout << "Stream is Science" << endl;
			} else {
				cout << "Stream is Commerce" << endl;
			}
        }
		void getData(int p1, int c1, int m1) {
		p = p1;
		c = c1;
		m = m1;
		}
		void putData() {
			cout << "Physics marks : " << p << endl;
			cout << "Chemistry marks : " << c << endl;
			cout << "Math marks : " << m << endl;
		}
};

class Stream: public Student, public Marks {
	private: 	
	public:
		void getStream(){
			calAvg();
		}
		
};
int main() {
    Stream s;
    s.getVal();
    s.getData(80,85,95);
    s.displayVal();
    s.putData();
    // s.calAvg();
    s.getStream();
  return 0;  
}