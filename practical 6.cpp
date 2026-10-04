/**
 * @file practical 6.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 6: Employee Details (Constructors & Destructors Lifecycle)
 */

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int emp_id;
    string name;

public:
    // Constructor
    Employee(int id, string n) {
        emp_id = id; // Fixed assignment bug: was emp_id - id
        name = n;
        cout << "Employee record created for " << name << endl;
    }

    // Display employee details
    void display() {
        cout << "Employee ID: " << emp_id << endl;
        cout << "Employee Name: " << name << endl;
    }

    // Destructor
    ~Employee() {
        cout << "Employee record removed for " << name << endl;
    }
};

int main() {
    // Creating an employee object
    Employee emp(101, "Anjali");

    // Displaying employee details
    emp.display();

    // Object is automatically destroyed when main() ends
    return 0;
}