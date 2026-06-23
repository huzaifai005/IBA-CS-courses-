#include<iostream>

class IWaterBreather {
public:
    virtual void waterBreathing() = 0;
    virtual ~IWaterBreather() {};
};

class IEggLayer {
public:
    virtual void laysEggs() = 0;
    virtual ~IEggLayer() {};
};

class IMilkProvider {
public:
    virtual void givesMilk() = 0;
    virtual ~IMilkProvider() {};
};

class IFlyer {
public:
    virtual void flies() = 0;
    virtual ~IFlyer() {};
};

class Amphibian : public IWaterBreather, public IEggLayer {
public:
~Amphibian() {};
};

class Birds : public IFlyer, public IEggLayer {
public: 
~Birds() {};
};

class Mammal : public IMilkProvider {
public: 
~Mammal() {};
};

class Platypus : public Mammal, public IEggLayer {
public:
    void givesMilk() override {
        std::cout << "Platypus gives milk." << std::endl;
    }

    void laysEggs() override {
        std::cout << "Platypus lays eggs." << std::endl;
    }
};

class Bat : public Mammal, public IFlyer {
public: 
    void givesMilk() override {
        std::cout << "Bat gives milk." << std::endl;
    }

    void flies() override {
        std::cout << "Bat flies." << std::endl;
    }
};

class Chimera : public IFlyer, public IEggLayer, public IWaterBreather, public IMilkProvider {
public:
     void givesMilk() override {
        std::cout << "Chimera gives milk." << std::endl;
    }

     void flies() override {
        std::cout << "Chimera flies." << std::endl;
    }

     void laysEggs() override {
        std::cout << "Chimera lays eggs." << std::endl;
    }

    void waterBreathing() override {
        std::cout << "Chimera breathes water." << std::endl;
    }
};


int main() {
    Platypus p1;
    p1.givesMilk();
    p1.laysEggs();

    Bat b1;
    b1.givesMilk();
    b1.flies();

    Chimera c1;
    c1.waterBreathing();
    c1.laysEggs();
    c1.givesMilk();
    c1.flies();

}


//To add all the animals to a linked list, you need to create a common interface like IAnimal that all animal classes implement. The linked list can store pointers to IAnimal, and you can call the showInfo() method on each animal, which will invoke the specific behavior of methods like givesMilk(), flies(), laysEggs(), or waterBreathing(), depending on the animal

