#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tire {
    // Private access specifier: Data members are encapsulated and not accessible outside the class
private:
    string brand;
    string size;

public:
    Tire(const string& brand, const string& size) : brand(brand), size(size) {}

    // Accessor method for brand
    string getBrand() const {
        return brand;
    }

    // Mutator method for brand
    void setBrand(const string& newBrand) {
        brand = newBrand;
    }

    // Accessor method for size
    string getSize() const {
        return size;
    }

    // Mutator method for size
    void setSize(const string& newSize) {
        size = newSize;
    }

    void displayInfo() const {
        cout << "Tire Brand: " << this->brand << ", Size: " << this->size << endl;
    }
};

class Vehicle {
    // Private access specifier: Data members are encapsulated and not accessible outside the class
private:
    string make;
    string model;
    Tire tire;  

public:
    Vehicle(const string& make, const string& model, const Tire& tire) : make(make), model(model), tire(tire) {}

    // Accessor method for make
    string getMake() const {
        return make;
    }

    // Mutator method for make
    void setMake(const string& newMake) {
        make = newMake;
    }

    // Accessor method for model
    string getModel() const {
        return model;
    }

    // Mutator method for model
    void setModel(const string& newModel) {
        model = newModel;
    }

    void displayInfo() const {
        cout << "Vehicle Make: " << this->make << ", Model: " << this->model << endl;
        cout << "Tire:" << endl;
        this->tire.displayInfo();  
    }
};

int main() {
    vector<Vehicle> vehicles = {
        Vehicle("Toyota", "Camry", Tire("Goodyear", "225/50R17")),
        Vehicle("Honda", "Accord", Tire("Michelin", "225/50R17")),
        Vehicle("Ford", "Mustang", Tire("Bridgestone", "225/50R17")),
        Vehicle("Chevrolet", "Malibu", Tire("Pirelli", "225/50R17")),
        Vehicle("Nissan", "Altima", Tire("Continental", "225/50R17"))
    };

    for (const auto& car : vehicles) {
        car.displayInfo();
        cout << endl;
    }

    return 0;
}
