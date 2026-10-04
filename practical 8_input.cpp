/**
 * @file practical 8_input.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 8 (Interactive): Employee & Manager (Multilevel Inheritance)
 */

#include <iostream>
#include <string>

using namespace std;

// Level 1: Base Class
class Person {
protected:
    string name;
    int age;
    string contact;

public:
    Person(string n, int a, string c) {
        name = n;
        age = a;
        contact = c;
    }

    void displayPerson() const {
        cout << "Name:        " << name << endl;
        cout << "Age:         " << age << endl;
        cout << "Contact:     " << contact << endl;
    }
};

// Level 2: Derived Class (inherits from Person)
class Employee : public Person {
protected:
    int employeeID;
    string department;

public:
    Employee(string n, int a, string c, int id, string dept) : Person(n, a, c) {
        employeeID = id;
        department = dept;
    }

    void displayEmployee() const {
        displayPerson();
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department:  " << department << endl;
    }
};

// Level 3: Derived Class (inherits from Employee)
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int a, string c, int id, string dept, int size)
        : Employee(n, a, c, id, dept) {
        teamSize = size;
    }

    void displayManager() const {
        cout << "\n--- Manager Dossier ---" << endl;
        displayEmployee();
        cout << "Team Size:   " << teamSize << endl;
    }
};

int main() {
    string name, contact, department;
    int age, employeeID, teamSize;

    cout << "=== Workforce Management System (Multilevel Inheritance) ===" << endl;
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Contact: ";
    getline(cin, contact);

    cout << "Enter Employee ID: ";
    cin >> employeeID;
    cin.ignore();

    cout << "Enter Department: ";
    getline(cin, department);

    cout << "Enter Team Size: ";
    cin >> teamSize;

    // Multi-tier construction across 3 levels
    Manager manager(name, age, contact, employeeID, department, teamSize);
    manager.displayManager();

    return 0;
}
