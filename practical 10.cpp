/**
 * @file practical 10.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 10: Function Template (Finding Maximum of Two Values)
 */

#include <iostream>

using namespace std;

// Function Template to find maximum of two values
template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << "=== Practical 10: Function Template (myMax) ===" << endl;

    // Comparing student marks
    cout << "Higher Marks: "
         << myMax<int>(75, 90) << endl;

    // Comparing product prices
    cout << "Higher Price: "
         << myMax<double>(499.50, 699.75) << endl;

    // Comparing sensor readings
    cout << "Higher Sensor Reading: "
         << myMax<float>(25.5f, 30.8f) << endl;

    return 0;
}
