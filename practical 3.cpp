/**
 * @file practical 3.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 3: Employee Record System (Encapsulation & Access Control)
 */

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    string department;
    double salary;

public:
    // Manual setup function to populate data
    void setDetails(int empid, string empName, string empDept, double empSal) {
        id = empid;
        name = empName;
        department = empDept;
        salary = empSal;
    }

    // Func. to display employee info (authorised access)
    void displayInfo(bool authorised) const {
        if (authorised) {
            cout << "ID: " << id << "\n";
            cout << "Name: " << name << "\n";
            cout << "Department: " << department << "\n";
            cout << "Salary: " << salary << "\n";
        } else {
            cout << "Access Denied\n";
        }
    }
};

int main() {
    // using std fixed size array
    const int MAX_EMPLOYEES = 2;
    Employee staffList[MAX_EMPLOYEES];

    staffList[0].setDetails(101, "Alice Smith", "HR", 55000.0);
    staffList[1].setDetails(102, "Bob Jones", "Engineer", 75000.0);

    bool isAuthorisedHR = true;

    cout << "\n--- Employee Record (HR View) ---\n";

    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        staffList[i].displayInfo(isAuthorisedHR);
    }

    return 0;
}