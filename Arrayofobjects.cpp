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
    Tire tire;  

public:
    Vehicle(const string& make, const string& model, const Tire& tire) : make(make), model(model), tire(tire) {}

    string getMake() const {
        return make;
    }

    string getModel() const {
        return model;
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

    for (const auto& vehicle : vehicles) {
        vehicle.displayInfo();
        cout << endl;
    }

    return 0;
}
