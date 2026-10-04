/**
 * @file practical 6_input.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 6 (Interactive): Employee Details with Console Input
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
        emp_id = id; 
        name = n;
        cout << "\nEmployee record created for " << name << endl;
    }

    // Display employee details
    void display() {
        cout << "\n--- Employee Details ---" << endl;
        cout << "Employee ID: " << emp_id << endl;
        cout << "Employee Name: " << name << endl;
    }

    // Destructor
    ~Employee() {
        cout << "Employee record removed for " << name << endl;
    }
};

int main() {
    int id;
    string name;

    // Taking input from the user
    cout << "Enter Employee ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Employee Name: ";
    getline(cin, name);

    // Creating an employee object using user input
    Employee emp(id, name);

    // Displaying employee details
    emp.display();

    return 0;
}