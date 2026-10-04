/**
 * @file practical 7_input.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 7 (Interactive): Person & Student (Single Inheritance)
 */

#include <iostream>
#include <string>

using namespace std;

// Base Class
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
};

// Derived Class inheriting from Person
class Student : public Person {
private:
    int rollNumber;
    string branch;

public:
    // Base class initialization using member initializer list
    Student(string n, int a, string c, int r, string b) : Person(n, a, c) {
        rollNumber = r;
        branch = b;
    }

    void display() const {
        cout << "\n--- Student Profile ---" << endl;
        cout << "Name:        " << name << endl;
        cout << "Age:         " << age << endl;
        cout << "Contact:     " << contact << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Branch:      " << branch << endl;
    }
};

int main() {
    string name, contact, branch;
    int age, rollNumber;

    cout << "=== Student Registration Portal (Single Inheritance) ===" << endl;
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter Contact Number: ";
    getline(cin, contact);

    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cin.ignore();

    cout << "Enter Branch: ";
    getline(cin, branch);

    // Instantiation with runtime console inputs
    Student s1(name, age, contact, rollNumber, branch);
    s1.display();

    return 0;
}
