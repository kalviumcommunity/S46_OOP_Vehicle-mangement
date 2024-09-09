#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tire {
private:
    string brand;
    string size;

public:
    Tire(const string& brand, const string& size) : brand(brand), size(size) {}

    string getBrand() const {
        return brand;
    }

    string getSize() const {
        return size;
    }

    void displayInfo() const {
        cout << "Tire Brand: " << this->brand << ", Size: " << this->size << endl;
    }
};

class Vehicle {
private:
    string make;
    string model;
    Tire* tire;  // Use a pointer to Tire

public:
    // Constructor with dynamic allocation for Tire
    Vehicle(const string& make, const string& model, Tire* tire) : make(make), model(model), tire(tire) {}

    ~Vehicle() {
        delete tire; // Free dynamically allocated memory for Tire
    }

    string getMake() const {
        return make;
    }

    string getModel() const {
        return model;
    }

    void displayInfo() const {
        cout << "Vehicle Make: " << this->make << ", Model: " << this->model << endl;
        cout << "Tire:" << endl;
        this->tire->displayInfo();  // Access tire via pointer
    }
};

int main() {
    // Dynamically allocate Tire objects
    Tire* tire1 = new Tire("Goodyear", "225/50R17");
    Tire* tire2 = new Tire("Michelin", "225/50R17");
    Tire* tire3 = new Tire("Bridgestone", "225/50R17");
    Tire* tire4 = new Tire("Pirelli", "225/50R17");
    Tire* tire5 = new Tire("Continental", "225/50R17");

    // Dynamically allocate Vehicle objects
    vector<Vehicle*> vehicles = {
        new Vehicle("Toyota", "Camry", tire1),
        new Vehicle("Honda", "Accord", tire2),
        new Vehicle("Ford", "Mustang", tire3),
        new Vehicle("Chevrolet", "Malibu", tire4),
        new Vehicle("Nissan", "Altima", tire5)
    };

    // Display information for each vehicle
    for (const auto& car : vehicles) {
        car->displayInfo();
        cout << endl;
    }

    // Deallocate memory for Vehicle objects
    for (auto& car : vehicles) {
        delete car;
    }

    return 0;
}
