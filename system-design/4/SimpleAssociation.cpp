#include <iostream>
#include <string>

class Car {
public:
    std::string model;
    Car(std::string m) : model(m) {}
    void drive() { std::cout << "Driving " << model << "\n"; }
};

class Person {
public:
    std::string name;
    Car* car; // Simple association: Person has a Car, but they are independent
    Person(std::string n, Car* c = nullptr) : name(n), car(c) {}
    void useCar() {
        if (car) car->drive();
        else std::cout << name << " has no car.\n";
    }
};

int main() {
    Car car("Toyota");
    Person person("Alice", &car); // Alice has a car
    person.useCar(); // Output: Driving Toyota

    Person person2("Bob"); // Bob has no car
    person2.useCar(); // Output: Bob has no car.
    return 0;
}