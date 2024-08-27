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
        cout << "Tire Brand: " << brand << ", Size: " << size << endl;
    }
};


class Vehicle {
private:
    string make;
    string model;
    Tire t1;  

public:
    
    Vehicle(const string& make, const string& model, const Tire& tire) : make(make), model(model), tire(tire) {}

    
    string getMake() const {
        return make;
    }

    string getModel() const {
        return model;
    }

    void displayInfo() const {
        cout << "Vehicle Make: " << make << ", Model: " << model << endl;
        cout << "Tire:" << endl;
        t1.displayInfo();
    }
};

int main() {

    string make = "Toyota";
    string model = "Camry";
    Tire tire("Goodyear", "225/50R17");

    Vehicle vehicle1(make, model, tire);

    vehicle.displayInfo();

    return 0;
}