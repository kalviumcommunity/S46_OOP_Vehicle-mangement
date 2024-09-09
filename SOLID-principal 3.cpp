#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract class with a pure virtual function (LSP Principle)
class Vehicle {
protected:
    string make;
    string model;

public:
    Vehicle(const string& make, const string& model) : make(make), model(model) {}

    // Pure virtual function (abstract function) (LSP Principle)
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

// Derived class that implements the pure virtual function (LSP Principle)
class Car : public Vehicle {
private:
    string fuelType;

public:
    Car(const string& make, const string& model, const string& fuelType)
        : Vehicle(make, model), fuelType(fuelType) {}

    void displayInfo() const override { // Override the pure virtual function (LSP Principle)
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

// Another derived class that implements the pure virtual function (LSP Principle)
class ElectricCar : public Vehicle {
private:
    int batteryCapacity;

public:
    ElectricCar(const string& make, const string& model, int batteryCapacity)
        : Vehicle(make, model), batteryCapacity(batteryCapacity) {}

    void displayInfo() const override { // Override the pure virtual function (LSP Principle)
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

// New derived class demonstrating extension without modifying existing classes (LSP Principle)
class HybridCar : public Vehicle {
private:
    string fuelType;
    int batteryCapacity;

public:
    HybridCar(const string& make, const string& model, const string& fuelType, int batteryCapacity)
        : Vehicle(make, model), fuelType(fuelType), batteryCapacity(batteryCapacity) {}

    void displayInfo() const override { // Override the pure virtual function (LSP Principle)
        cout << "Vehicle Make: " << make << ", Model: " << model << endl;
        cout << "Fuel Type: " << fuelType << ", Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }

    // Accessor methods
    string getFuelType() const {
        return fuelType;
    }

    int getBatteryCapacity() const {
        return batteryCapacity;
    }

    // Mutator methods
    void setFuelType(const string& newFuelType) {
        fuelType = newFuelType;
    }

    void setBatteryCapacity(int newCapacity) {
        batteryCapacity = newCapacity;
    }
};

// Class that manages Vehicle objects
class VehicleManager {
private:
    vector<Vehicle*> vehicles;

public:
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void displayAll() const {
        for (const auto& vehicle : vehicles) {
            vehicle->displayInfo(); // Calls the appropriate derived class method (LSP Principle)
            cout << endl;
        }
    }

    ~VehicleManager() {
        for (auto& vehicle : vehicles) {
            delete vehicle; // Clean up dynamically allocated memory
        }
    }
};

int main() {
    VehicleManager manager;

    // Create and add vehicles to manager
    manager.addVehicle(new Car("Toyota", "Camry", "Petrol"));
    manager.addVehicle(new ElectricCar("Tesla", "Model S", 100));
    manager.addVehicle(new HybridCar("Honda", "Clarity", "Petrol", 50));

    // Display all vehicles
    manager.displayAll();

    return 0;
}
