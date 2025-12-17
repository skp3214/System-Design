#include <iostream>
using namespace std;

// Base Class
class Car {
protected:
    int speed;
    string brand;

public:
    Car(string b = "Generic", int s = 0) {
        brand = b;
        speed = s;
    }

    // Overloaded method: same name, different parameters
    void start() {
        cout << brand << " is starting." << endl;
    }

    void start(string mode) {
        cout << brand << " is starting in " << mode << " mode." << endl;
    }

    // Virtual function for overriding
    virtual void displayInfo() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
    }
};

// Derived Class 1
class ElectricCar : public Car {
    int batteryLevel;

public:
    ElectricCar(string b, int s, int battery) : Car(b, s), batteryLevel(battery) {}

    // Override base class method
    void displayInfo() override {
        cout << "Electric Car - Brand: " << brand << ", Speed: " << speed 
             << " km/h, Battery: " << batteryLevel << "%" << endl;
    }
};

// Derived Class 2
class ManualCar : public Car {
    string gearType;

public:
    ManualCar(string b, int s, string gear) : Car(b, s), gearType(gear) {}

    // Override base class method
    void displayInfo() override {
        cout << "Manual Car - Brand: " << brand << ", Speed: " << speed 
             << " km/h, Gear Type: " << gearType << endl;
    }
};

// Derived Class 3
class HybridCar : public Car {
    float fuelEfficiency;

public:
    HybridCar(string b, int s, float efficiency) : Car(b, s), fuelEfficiency(efficiency) {}

    // Override base class method
    void displayInfo() override {
        cout << "Hybrid Car - Brand: " << brand << ", Speed: " << speed 
             << " km/h, Fuel Efficiency: " << fuelEfficiency << " km/l" << endl;
    }
};

// Main Function
int main() {
    Car base("Generic", 60);
    ElectricCar tesla("Tesla", 120, 85);
    ManualCar suzuki("Suzuki", 80, "5-speed");
    HybridCar prius("Toyota Prius", 100, 22.5);

    // --- Overloading ---
    base.start();             // Basic start
    base.start("Eco");        // Overloaded start

    cout << "\n--- Overriding (Polymorphism) ---" << endl;

    // --- Polymorphism ---
    Car* carPtr;

    carPtr = &tesla;
    carPtr->displayInfo();    // ElectricCar's version

    carPtr = &suzuki;
    carPtr->displayInfo();    // ManualCar's version

    carPtr = &prius;
    carPtr->displayInfo();    // HybridCar's version

    return 0;
}
