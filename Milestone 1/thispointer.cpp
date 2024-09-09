#include <iostream>
#include <string>

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
    
    string make = "Toyota";
    string model = "Camry";
    Tire tire("Goodyear", "225/50R17");

    
    Vehicle vehicle(make, model, tire);

    
    vehicle.displayInfo();

    return 0;
}
