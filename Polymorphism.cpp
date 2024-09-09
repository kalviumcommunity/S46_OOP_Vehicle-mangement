#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class
class BaseVehicle {
protected:
    string make;
    string model;

public:
    BaseVehicle(const string& make, const string& model) : make(make), model(model) {}

    // Base class function that will be overridden in derived classes
    virtual void displayInfo() const {
        cout << "Vehicle Make: " << make << ", Model: " << model << endl;
    }

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
};

// Derived class (Single Inheritance)
class Car : public BaseVehicle {
private:
    string fuelType;

public:
    Car(const string& make, const string& model, const string& fuelType)
        : BaseVehicle(make, model), fuelType(fuelType) {}

    // Override the base class function
    void displayInfo() const override { // Polymorphism through function overriding
        BaseVehicle::displayInfo(); // Display base class info
        cout << "Fuel Type: " << fuelType << endl;
    }

    // Overloaded displayInfo to provide more details
    void displayInfo(const string& additionalInfo) const { // Polymorphism through function overloading
        BaseVehicle::displayInfo(); // Display base class info
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Additional Info: " << additionalInfo << endl;
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

// Another base class for multiple inheritance
class BatteryPowered {
protected:
    int batteryCapacity;

public:
    BatteryPowered(int capacity) : batteryCapacity(capacity) {}

    void displayBatteryInfo() const {
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

// Derived class (Multiple Inheritance)
class ElectricCar : public Car, public BatteryPowered {
public:
    ElectricCar(const string& make, const string& model, const string& fuelType, int batteryCapacity)
        : Car(make, model, fuelType), BatteryPowered(batteryCapacity) {}

    // Override the base class function
    void displayInfo() const override { // Polymorphism through function overriding
        Car::displayInfo(); // Display info from Car
        displayBatteryInfo(); // Display info from BatteryPowered
    }

    // Overloaded displayInfo method
    void displayInfo(const string& additionalInfo) const { // Polymorphism through function overloading
        Car::displayInfo(additionalInfo); // Use the overloaded method from Car
        displayBatteryInfo(); // Display info from BatteryPowered
    }
};

int main() {
    vector<ElectricCar> vehicles = {
        ElectricCar("Tesla", "Model S", "Electric", 100),
        ElectricCar("Nissan", "Leaf", "Electric", 40)
    };

    for (const auto& car : vehicles) {
        car.displayInfo(); // Calls overridden method in ElectricCar
        cout << endl;

        car.displayInfo("Advanced model with autopilot"); // Calls overloaded method in ElectricCar
        cout << endl;
    }

    return 0;
}
