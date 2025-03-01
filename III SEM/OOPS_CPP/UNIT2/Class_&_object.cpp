#include <iostream>
#include <string>
using namespace std;
class Details_of_student {
    string name;
    int roll_number;
    float percentage;
    public:
    void get_details(string str, int r, int p);
    void put_details() {
        cout << "Student name is -> " << name << endl;
        cout << "Student roll number is -> " << roll_number << endl;
        cout << "Student percentage is -> " << percentage << endl;
    }
};
void Details_of_student :: get_details(string str, int r, int p) {
    name = str;
    roll_number = r;
    percentage = p;
}
int main() {
    Details_of_student s;
    s.get_details("Anu", 1, 99);
    s.put_details();
    return 0;
}