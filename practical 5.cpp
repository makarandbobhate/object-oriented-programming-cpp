/**
 * @file practical 5.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 5: Student Details ('this' Pointer Disambiguation)
 */

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    string course;

public:
    // Constructor
    Student(int rollNumber, string name, string course) {
        this->rollNumber = rollNumber;
        this->name = name;
        this->course = course;
    }

    // Display student details
    void displayDetails() {
        cout << "Student Details" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
    }
};

int main() {
    Student s1(101, "Anjali", "Computer Science");
    s1.displayDetails();
    return 0;
}
