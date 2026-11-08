/**
 * @file practical 11.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 11: Function Template (Generic Value Swapping)
 */

#include <iostream>

using namespace std;

// Function Template to swap two values by reference
template <typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    cout << "=== Practical 11: Function Template (mySwap) ===" << endl;

    // Swapping Employee IDs
    int emp1 = 101, emp2 = 102;
    mySwap(emp1, emp2);
    cout << "Employee IDs after swap: "
         << emp1 << " " << emp2 << endl;

    // Swapping Room Numbers
    int room1 = 201, room2 = 205;
    mySwap(room1, room2);
    cout << "Room Numbers after swap: "
         << room1 << " " << room2 << endl;

    // Swapping Task Priorities
    float p1 = 1.5, p2 = 2.5;
    mySwap(p1, p2);
    cout << "Task Priorities after swap: "
         << p1 << " " << p2 << endl;

    return 0;
}

