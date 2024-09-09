# Vehicle Management System

## Overview

This C++ program demonstrates basic Object-Oriented Programming (OOP) principles by modeling a simple vehicle management system. The program defines an abstract class `Vehicle` and two derived classes, `Car` and `ElectricCar`, to show polymorphism and adherence to the Liskov Substitution Principle (LSP). The program also highlights the use of abstract classes, virtual functions, and inheritance.

## Classes

### Vehicle Class (Abstract Base Class)

- **Attributes**:
  - `make`: The make (brand) of the vehicle.
  - `model`: The model of the vehicle.

- **Methods**:
  - `displayInfo()`: Pure virtual function. This method must be overridden by derived classes to display specific vehicle details.
  - `getMake()`: Returns the make of the vehicle.
  - `getModel()`: Returns the model of the vehicle.
  - `setMake(const string& newMake)`: Sets the make of the vehicle.
  - `setModel(const string& newModel)`: Sets the model of the vehicle.
  - `~Vehicle()`: Virtual destructor to ensure proper cleanup of derived class objects.

### Car Class (Derived from Vehicle)

- **Attributes**:
  - `fuelType`: The type of fuel used by the car.

- **Methods**:
  - `displayInfo()`: Overrides the pure virtual function from `Vehicle`. Displays the car's make, model, and fuel type.
  - `getFuelType()`: Returns the fuel type of the car.
  - `setFuelType(const string& newFuelType)`: Sets the fuel type of the car.

### ElectricCar Class (Derived from Vehicle)

- **Attributes**:
  - `batteryCapacity`: The capacity of the battery in kilowatt-hours (kWh).

- **Methods**:
  - `displayInfo()`: Overrides the pure virtual function from `Vehicle`. Displays the electric car's make, model, and battery capacity.
  - `getBatteryCapacity()`: Returns the battery capacity of the electric car.
  - `setBatteryCapacity(int newCapacity)`: Sets the battery capacity of the electric car.

## Usage

In the `main()` function, a vector of pointers to `Vehicle` is created. This vector holds instances of `Car` and `ElectricCar`. The `displayInfo()` method is called for each vehicle, demonstrating polymorphism. The program uses the base class pointer to invoke derived class methods, showcasing the Liskov Substitution Principle (LSP).

## Key Points Demonstrated

- **Abstract Classes and Virtual Functions**:
  - The `Vehicle` class is an abstract class with a pure virtual function `displayInfo()`. Derived classes must implement this function.

- **Liskov Substitution Principle (LSP)**:
  - Derived classes (`Car` and `ElectricCar`) override the `displayInfo()` method from the `Vehicle` class. Objects of these derived classes can be used interchangeably where a `Vehicle` is expected, ensuring that the derived classes conform to the expected behavior of the base class.

- **Polymorphism**:
  - The program demonstrates polymorphism by using a vector of base class pointers (`Vehicle*`) to manage different types of derived class objects (`Car` and `ElectricCar`).
