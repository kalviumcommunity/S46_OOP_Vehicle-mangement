#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tire {
private:
    string brand;
    string size;

    // Static variable to track the number of Tire instances
    static int tireCount;

public:
    // Default constructor
    Tire() : brand("Unknown"), size("Unknown") {
        ++tireCount;
    }

    // Parameterized constructor
    Tire(const string& brand, const string& size) : brand(brand), size(size) {
        ++tireCount;
    }

    // Destructor
    ~Tire() {
        --tireCount;
    }

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

    // Static method to get the number of Tire instances
    static int getTireCount() {
        return tireCount;
    }

    // Static member function to display a message
    static void displayMessage() {
        cout << "Tire class has been instantiated " << getTireCount() << " times." << endl;
    }
};

// Initialize static variable
int Tire::tireCount = 0;

class Vehicle {
private:
    string make;
    string model;
    Tire* tire;

    // Static variable to track the number of Vehicle instances
    static int vehicleCount;

public:
    // Default constructor
    Vehicle() : make("Unknown"), model("Unknown"), tire(new Tire()) {
        ++vehicleCount;
    }

    // Parameterized constructor
    Vehicle(const string& make, const string& model, Tire* tire) : make(make), model(model), tire(tire) {
        ++vehicleCount;
    }

    // Destructor
    ~Vehicle() {
        --vehicleCount;
        delete tire; // Delete the dynamically allocated Tire object
    }

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
        this->tire->displayInfo();  // Access tire via pointer
    }

    // Static method to get the number of Vehicle instances
    static int getVehicleCount() {
        return vehicleCount;
    }

    // Static member function to display a message
    static void displayMessage() {
        cout << "Vehicle class has been instantiated " << getVehicleCount() << " times." << endl;
    }
};

// Initialize static variable
int Vehicle::vehicleCount = 0;

int main() {
    // Create Tire objects using both constructors
    Tire* tire1 = new Tire("Goodyear", "225/50R17"); // Parameterized constructor
    Tire* tire2 = new Tire(); // Default constructor
    tire2->setBrand("Michelin");
    tire2->setSize("225/50R17");

    // Create Vehicle objects using both constructors
    vector<Vehicle*> vehicles = {
        new Vehicle("Toyota", "Camry", tire1), // Parameterized constructor
        new Vehicle() // Default constructor
    };

    // Assign tire2 to the default Vehicle
    vehicles[1]->setMake("Honda");
    vehicles[1]->setModel("Accord");
    delete vehicles[1]->tire; // Clean up old tire
    vehicles[1]->tire = tire2;

    // Display information for each vehicle
    for (const auto& car : vehicles) {
        car->displayInfo();
        cout << endl;
    }

    // Call static member functions
    Tire::displayMessage(); 
    Vehicle::displayMessage(); 

    // Deallocate memory for Vehicle objects
    for (auto& car : vehicles) {
        delete car;
    }

    // Display the number of Tire instances after deletion
    cout << "Total Tire instances after deletion: " << Tire::getTireCount() << endl;

    return 0;
}
