/**
 * @file practical 9_input.cpp
 * @author Makarand Pankaj Bobhate (Roll No: 09, Div: 5)
 * @institution MIT ADT University, School of AI
 * @course Object Oriented Programming (OOPS)
 * @brief Practical 9 (Interactive): Vehicle, Car, Truck (Hierarchical Inheritance)
 */

#include <iostream>
#include <string>

using namespace std;

// Base Class common to all vehicles
class Vehicle {
protected:
    string registrationNo;
    string brand;

public:
    Vehicle(string reg, string b) {
        registrationNo = reg;
        brand = b;
    }

    void displayCommon() const {
        cout << "Registration: " << registrationNo << endl;
        cout << "Brand:        " << brand << endl;
    }
};

// Branch 1: Car
class Car : public Vehicle {
private:
    int seats;

public:
    Car(string reg, string b, int s) : Vehicle(reg, b) {
        seats = s;
    }

    void display() const {
        cout << "\n--- Car Specification ---" << endl;
        displayCommon();
        cout << "Seating Cap:  " << seats << " passengers" << endl;
        cout << "--------------------------" << endl;
    }
};

// Branch 2: Truck
class Truck : public Vehicle {
private:
    double loadCapacity;

public:
    Truck(string reg, string b, double load) : Vehicle(reg, b) {
        loadCapacity = load;
    }

    void display() const {
        cout << "\n--- Truck Specification ---" << endl;
        displayCommon();
        cout << "Payload Cap:  " << loadCapacity << " metric tons" << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    string reg, brand;
    int seats;
    double loadCapacity;

    cout << "=== Transport Fleet Registry (Hierarchical Inheritance) ===" << endl;
    
    // Registering Car
    cout << "\n[Input Car Details]" << endl;
    cout << "Enter Registration No: ";
    getline(cin, reg);
    cout << "Enter Brand: ";
    getline(cin, brand);
    cout << "Enter Seating Capacity: ";
    cin >> seats;
    cin.ignore();

    Car userCar(reg, brand, seats);

    // Registering Truck
    cout << "\n[Input Truck Details]" << endl;
    cout << "Enter Registration No: ";
    getline(cin, reg);
    cout << "Enter Brand: ";
    getline(cin, brand);
    cout << "Enter Load Capacity (tons): ";
    cin >> loadCapacity;

    Truck userTruck(reg, brand, loadCapacity);

    // Display records
    cout << "\n================ Registered Fleet ================";
    userCar.display();
    userTruck.display();

    return 0;
}
