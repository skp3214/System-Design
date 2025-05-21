#include <iostream>
using namespace std;

// Base class
class Car {
private:
    string fuelType;

protected:
    int speed;

public:
    string brand;

    Car(string b = "Generic", string fuel = "Petrol", int s = 0) {
        brand = b;
        fuelType = fuel;
        speed = s;
    }

    void start() {
        cout << brand << " is starting." << endl;
    }

    void stop() {
        cout << brand << " is stopping." << endl;
    }

    void displayInfo() {
        cout << "Brand: " << brand << ", Fuel: " << fuelType << ", Speed: " << speed << " km/h" << endl;
    }
};

// Child class 1: Public Inheritance
class ElectricCar : public Car {
public:
    int batteryPercentage;

    ElectricCar(string b, int s, int battery)
        : Car(b, "Electric", s), batteryPercentage(battery) {}

    void charge() {
        cout << brand << " is charging. Battery: " << batteryPercentage << "%" << endl;
    }
};

// Child class 2: Private Inheritance
class ManualCar : private Car {
public:
    int gearCount;

    ManualCar(string b, int s, int gears)
        : Car(b, "Petrol", s), gearCount(gears) {}

    void showManualInfo() {
        // We can access protected and public members of Car inside the derived class
        cout << "Manual Car - Brand: " << brand << ", Gears: " << gearCount << ", Speed: " << speed << endl;
    }
};

// Child class 3: Protected Inheritance
class HybridCar : protected Car {
public:
    bool isElectricMode;

    HybridCar(string b, int s, bool mode)
        : Car(b, "Hybrid", s), isElectricMode(mode) {}

    void toggleMode() {
        isElectricMode = !isElectricMode;
        cout << brand << " is now in " << (isElectricMode ? "Electric" : "Manual") << " mode." << endl;
    }

    void showHybridInfo() {
        cout << "Hybrid Car - Brand: " << brand << ", Speed: " << speed << ", Mode: " << (isElectricMode ? "Electric" : "Manual") << endl;
    }
};

// Main function
int main() {
    ElectricCar tesla("Tesla Model S", 250, 80);
    tesla.start();
    tesla.displayInfo();
    tesla.charge();
    tesla.stop();

    cout << "------------------" << endl;

    ManualCar suzuki("Suzuki Swift", 180, 5);
    suzuki.showManualInfo(); // Can access info via its own method

    cout << "------------------" << endl;

    HybridCar toyota("Toyota Prius", 200, true);
    toyota.toggleMode();
    toyota.showHybridInfo();

    return 0;
}
