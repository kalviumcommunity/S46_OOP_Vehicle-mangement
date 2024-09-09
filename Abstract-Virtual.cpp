#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract class with a pure virtual function
class Vehicle {
protected:
    string make;
    string model;

public:
    Vehicle(const string& make, const string& model) : make(make), model(model) {}

    // Pure virtual function (abstract function)
    virtual void displayInfo() const = 0;

    // Accessor methods
    string getMake() const {
        return make;
    }

    string getModel() const {
        return model;
    }

    // Mutator methods
    void setMake(const string& newMake) {
        make = newMake;
    }

    void setModel(const string& newModel) {
        model = newModel;
    }

    virtual ~Vehicle() = default; // Virtual destructor
};

// Derived class that implements the pure virtual function
class Car : public Vehicle {
private:
    string fuelType;

public:
    Car(const string& make, const string& model, const string& fuelType)
        : Vehicle(make, model), fuelType(fuelType) {}

    void displayInfo() const override { // Override the pure virtual function
        cout << "Vehicle Make: " << make << ", Model: " << model << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }

    // Accessor methods
    string getFuelType() const {
        return fuelType;
    }

    // Mutator methods
    void setFuelType(const string& newFuelType) {
        fuelType = newFuelType;
    }
};

// Another derived class that implements the pure virtual function
class ElectricCar : public Vehicle {
private:
    int batteryCapacity;

public:
    ElectricCar(const string& make, const string& model, int batteryCapacity)
        : Vehicle(make, model), batteryCapacity(batteryCapacity) {}

    void displayInfo() const override { // Override the pure virtual function
        cout << "Vehicle Make: " << make << ", Model: " << model << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }

    // Accessor methods
    int getBatteryCapacity() const {
        return batteryCapacity;
    }

    // Mutator methods
    void setBatteryCapacity(int newCapacity) {
        batteryCapacity = newCapacity;
    }
};

int main() {
    // Create a vector of pointers to the base class
    vector<Vehicle*> vehicles = {
        new Car("Toyota", "Camry", "Petrol"),
        new ElectricCar("Tesla", "Model S", 100)
    };

    // Call the overridden displayInfo method through base class pointers
    for (const auto& vehicle : vehicles) {
        vehicle->displayInfo(); // Calls the appropriate derived class method
        cout << endl;
    }

    // Clean up
    for (auto& vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
