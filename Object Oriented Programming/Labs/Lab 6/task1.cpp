#include<iostream>

class IVehicle {
public: 
    virtual void accelerate(int speed) = 0;
    virtual void decelerate(int speed) = 0;
    virtual ~IVehicle() {};
};

class IConvertible {
public: 
    virtual void openRoof() = 0;
    virtual ~IConvertible() {};
};

class Car : public IVehicle {
public:
    virtual void startEngine() = 0;
    ~Car() {};
};

class Sedan : public Car, public IConvertible {
public: 
    void accelerate(int speed) override {
        std::cout << "Sedan is accelerating at " << speed << " km/h." << std::endl;
    }

    void decelerate(int speed) override {
        std::cout << "Sedan is decelerating at " << speed << " km/h." << std::endl;
    }

    void openRoof() override {
        std::cout << "Sedan roof opened." << std::endl;
    }

    void startEngine() override {
        std::cout << "Sedan engine started." << std::endl;
    }


};

class SUV : public Car {
public: 
    void accelerate(int speed) override {
        std::cout << "SUV is accelerating at " << speed << " km/h." << std::endl;
    }

    void decelerate(int speed) override {
        std::cout << "SUV is decelerating at " << speed << " km/h." << std::endl;
    }

    void startEngine() override {
        std::cout << "SUV engine started." << std::endl;
    }


};

int main() {
    

    Car* s1 = new Sedan();
    IConvertible* s1Roof = new Sedan();

    s1->startEngine();
    s1->accelerate(100);
    s1->decelerate(50);
    s1Roof->openRoof();

    Car* s2 = new SUV();
    s2->startEngine();
    s2->accelerate(120);
    s2->decelerate(60);




}