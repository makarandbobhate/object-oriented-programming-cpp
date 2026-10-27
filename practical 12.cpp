/**
 * @file practical 12.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 12: Class Template (Generic Data Storage & Display)
 */

#include <iostream>
#include <string>

using namespace std;

// Class Template for generic data holding and display
template <typename T>
class Data {
private:
    T value;

public:
    // Constructor
    Data(T v) {
        value = v;
    }

    // Display Function
    void display() const {
        cout << "Stored Value: " << value << endl;
    }
};

int main() {
    cout << "=== Practical 12: Class Template (Data) ===" << endl;

    // Storing Integer Value
    Data<int> d1(100);

    // Storing Decimal Value
    Data<double> d2(95.75);

    // Storing Text Value
    Data<string> d3("Computer Science");

    d1.display();
    d2.display();
    d3.display();

    return 0;
}
