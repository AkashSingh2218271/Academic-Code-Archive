#include <iostream>
using namespace std;

// A class to represent a counter
class Counter {
  private:
    int value; // the value of the counter
  public:
    // Constructor to initialize the value
    Counter(int v = 0) {
      value = v;
    }

    // A friend function to overload the postfix increment operator
    friend Counter operator++(Counter &c, int);

    // A friend function to overload the postfix decrement operator
    friend Counter operator--(Counter &c, int);

    // A function to display the value of the counter
    void display() {
      cout << "The value of the counter is " << value << endl;
    }
};

// The definition of the friend function to overload the postfix increment operator
Counter operator++(Counter &c, int) {
  // Create a temporary object to store the original value of the counter
  Counter temp = c;
  // Increment the value of the counter by one
  c.value++;
  // Return the temporary object as the result of the operation
  return temp;
}

// The definition of the friend function to overload the postfix decrement operator
Counter operator--(Counter &c, int) {
  // Create a temporary object to store the original value of the counter
  Counter temp = c;
  // Decrement the value of the counter by one
  c.value--;
  // Return the temporary object as the result of the operation
  return temp;
}

// A main function to test the program
int main() {
  // Create a counter object with initial value 10
  Counter c(10);
  // Display the value of the counter
  c.display();
  // Apply the postfix increment operator and assign the result to another object
  Counter d = c++;
  // Display the values of both objects
  c.display();
  d.display();
  // Apply the postfix decrement operator and assign the result to another object
  Counter e = c--;
  // Display the values of both objects
  c.display();
  e.display();
  return 0;
}
