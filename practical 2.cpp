#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    string course;
    int admissionYear;

public:
    // Function to input student data
    void inputDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // Clear buffer before reading string input

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Admission Year: ";
        cin >> admissionYear;

        cout << "------------------------------------\n";
    }

    // Function to display student data
    void displayDetails() const {
        cout << "Roll Number:    " << rollNumber << "\n";
        cout << "Name:           " << name << "\n";
        cout << "Course:         " << course << "\n";
        cout << "Admission Year: " << admissionYear << "\n";
        cout << "------------------------------------\n";
    }

    // Getter function to retrieve roll number for search operations
    int getRollNumber() const {
        return rollNumber;
    }
};

int main() {
    const int MAX_STUDENTS = 100;
    Student database[MAX_STUDENTS];
    int currentCount = 0;
    int choice;

    cout << "=== College Record Digitization System ===\n";

    do {
        // Display Menu
        cout << "\n1. Add New Student Record\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (currentCount < MAX_STUDENTS) {
                    cout << "\n-- Enter Details for Student " << currentCount + 1 << " --\n";
                    database[currentCount].inputDetails();
                    currentCount++;
                    cout << "Record added successfully!\n";
                } else {
                    cout << "Database full! Cannot add more records.\n";
                }
                break;
            }

            case 2: {
                if (currentCount == 0) {
                    cout << "\nNo records found in the database.\n";
                } else {
                    cout << "\n--- All Student Records ---\n";
                    for (int i = 0; i < currentCount; i++) {
                        cout << "Record #" << (i + 1) << ":\n";
                        database[i].displayDetails();
                    }
                }
                break;
            }

            case 3: {
                if (currentCount == 0) {
                    cout << "\nDatabase is empty. No records to search.\n";
                } else {
                    int searchRoll;
                    bool found = false;
                    cout << "\nEnter Roll Number to search: ";
                    cin >> searchRoll;

                    for (int i = 0; i < currentCount; i++) {
                        if (database[i].getRollNumber() == searchRoll) {
                            cout << "\nRecord found:\n";
                            database[i].displayDetails();
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        cout << "Student with Roll Number " << searchRoll << " not found.\n";
                    }
                } 
                break;
            }

            case 4:
                cout << "\nExiting system. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice! Please enter a number between 1 and 4.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}