/**
 * @file practical 1.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 1: Digital Book Inventory System (Classes & Objects)
 */

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    double price;

public:
    // Function to record book information
    void recordBook() {
        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();
    }

    // Function to display Book Info
    void displayBook() {
        cout << "\n--- Book Information ---" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    Book book;
    cout << "=== Digital Book Inventory System ===" << endl;

    book.recordBook();
    book.displayBook();
    
    return 0;
}