# Vehicle and Tire Management System

## Overview

This C++ program demonstrates basic Object-Oriented Programming (OOP) principles by modeling a simple vehicle and tire management system. The program defines two classes, `Vehicle` and `Tire`, and demonstrates the use of these classes to manage and display information about vehicles and their associated tires. It includes the following features:

- **Vehicle Class**: Represents a vehicle with a make, model, and a single tire.
- **Tire Class**: Represents a tire with a brand and size.
- **Use of `this` Pointer**: Illustrates how to use the `this` pointer to access member variables and methods within class methods.
- **Multiple Vehicles and Tires**: Demonstrates the management of multiple vehicles, each associated with a unique tire.

## Classes

### Tire Class

- **Attributes**:
  - `brand`: The brand of the tire.
  - `size`: The size of the tire.
  
- **Methods**:
  - `displayInfo()`: Prints the tire's brand and size.

### Vehicle Class

- **Attributes**:
  - `make`: The make (brand) of the vehicle.
  - `model`: The model of the vehicle.
  - `tire`: An instance of the `Tire` class representing the tire associated with the vehicle.

- **Methods**:
  - `displayInfo()`: Prints the vehicle's make and model, and calls the `displayInfo()` method of the associated tire.

