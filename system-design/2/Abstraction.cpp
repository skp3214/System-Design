
#include <iostream>
using namespace std;

class Car{
    public:
        virtual void startEngine() = 0; // pure virtual function
        virtual void stopEngine() = 0; // pure virtual function
        virtual void drive() = 0; // pure virtual function
        virtual ~Car() {} // virtual destructor
};

class Tesla : public Car{

    public:
        string name;
        string model;
        bool isElectric;
        int currentSpeed;
        int maxSpeed;

        Tesla(string name, string model, bool isElectric, int currentSpeed, int maxSpeed) {
            this->name = name;
            this->model = model;
            this->isElectric = isElectric;
            this->currentSpeed = currentSpeed;
            this->maxSpeed = maxSpeed;
        }

        void startEngine() override {
            cout << "Tesla engine started" << endl;
        }
        void stopEngine() override {
            cout << "Tesla engine stopped" << endl;
        }
        void drive() override {
            cout << "Tesla is driving" << endl;
        }
};


int main(int argc, char const *argv[])
{
    Car *car = new Tesla("Tesla", "Model S", true, 0, 200);
    car->startEngine(); // Abstraction 
    car->drive();
    car->stopEngine();
    delete car; // free memory

    return 0;
}
