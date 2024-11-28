#include <iostream>
#include <string>
using namespace std;

// Base class Vehicle
class Vehicle {
private:
    string brand;
    string model;
    int year;

public:
    // Constructor
    Vehicle(string b, string m, int y) : brand(b), model(m), year(y) {}

    // Virtual function for display details (Polymorphism)
    virtual void displayDetails() = 0;

    // Getter functions (Encapsulation)
    string getBrand() { return brand; }
    string getModel() { return model; }
    int getYear() { return year; }
};

// Derived class Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    // Constructor
    Car(string b, string m, int y, int d) : Vehicle(b, m, y), numDoors(d) {}

    // Overriding the virtual function displayDetails() (Polymorphism)
    void displayDetails() override {
        cout << "Car Details:" << endl;
        cout << "Brand: " << getBrand() << endl;
        cout << "Model: " << getModel() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Number of doors: " << numDoors << endl;
    }
};

// Derived class Bike
class Bike : public Vehicle {
private:
    string type;

public:
    // Constructor
    Bike(string b, string m, int y, string t) : Vehicle(b, m, y), type(t) {}

    // Overriding the virtual function displayDetails() (Polymorphism)
    void displayDetails() override {
        cout << "Bike Details:" << endl;
        cout << "Brand: " << getBrand() << endl;
        cout << "Model: " << getModel() << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Type: " << type << endl;
    }
};

int main() {
    // Create a Car object
    Vehicle* myCar = new Car("Toyota", "Corolla", 2020, 4);

    // Create a Bike object
    Vehicle* myBike = new Bike("Yamaha", "YZF-R1", 2022, "Sport");

    // Use Polymorphism to call the displayDetails method for both objects
    cout << "Using Vehicle pointer to call displayDetails()" << endl;
    myCar->displayDetails();  // Calls Car's displayDetails
    cout << endl;
    myBike->displayDetails(); // Calls Bike's displayDetails

    // Cleanup
    delete myCar;
    delete myBike;

    return 0;
}
