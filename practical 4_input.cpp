/**
 * @file practical 4_input.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 4 (Interactive): Book Store (Default & Parameterized Constructors)
 */

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    int bookID;
    string title;
    string author;
    double price;

public:
    // Default constructor initializing baseline attributes
    Book() {
        bookID = 101;
        title = "C++ Programming";
        author = "Bjarne Stroustrup";
        price = 500.00;
    }

    // Parameterized constructor initializing attributes with custom arguments
    Book(int id, string t, string a, double p) {
        bookID = id;
        title = t;
        author = a;
        price = p;
    }

    // Function to display book details
    void display() const {
        cout << "Book ID: " << bookID << endl;
        cout << "Title:   " << title << endl;
        cout << "Author:  " << author << endl;
        cout << "Price:   Rs. " << price << endl;
        cout << "------------------------------------" << endl;
    }
};

int main() {
    int id;
    string title;
    string author;
    double price;

    cout << "=== Bookstore Inventory (Constructor Overloading) ===" << endl;

    // 1. Instantiating via Default Constructor
    Book book1;
    cout << "\n[Default Constructor Book Initialized]" << endl;
    book1.display();

    // 2. Taking user input for Parameterized Constructor
    cout << "\n[Input Custom Book Details for Parameterized Constructor]" << endl;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Price (Rs.): ";
    cin >> price;

    // Instantiating via Parameterized Constructor with user inputs
    Book book2(id, title, author, price);

    cout << "\n--- Custom Book Record (Parameterized) ---" << endl;
    book2.display();

    return 0;
}
