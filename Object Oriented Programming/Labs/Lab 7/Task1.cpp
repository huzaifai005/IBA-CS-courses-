#include<iostream>

class Base {
private:
int* dynamicInt;

public:
Base() {
        std::cout << "Base Constructor" << std::endl;
        dynamicInt = new int(10);
    }

virtual ~Base() {
    delete dynamicInt;
    std::cout << "Base Destructor" << std::endl;
}
};

class Intermediate : public Base {
public:
Intermediate() {
    std::cout << "Intermediate Constructor" << std::endl;
}

 ~Intermediate() {
    std::cout << "Intermediate Destructor" << std::endl;
}
};

//wrong way:
// class Final : public Intermediate {
// public:
// Final() {
//     std::cout << "Final Consrtuctor" << std::endl;
// }

// ~Final() {
//     std::cout << "Final Destructor" << std::endl;
//     throw std::runtime_error("error");
// }
// };

//right way: 
class Final : public Intermediate {
public:
Final() {
    std::cout << "Final Consrtuctor" << std::endl;
}

~Final() {
    try{
    std::cout << "Final Destructor" << std::endl;
    throw std::runtime_error("error");
    }
    catch(std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}
};



int main () {
try{ 
    Base* obj = new Final();
    delete obj;
}
catch (std::runtime_error &e) {
    std::cerr << e.what();
}
}

//reasoning: 
//we need to catch the error in the same scope, if we do not do that, the program terminates.
//to fix the issue we used try and catch in the destructor of the final class so that our program does not terminate due to an error being generated 
//since the program was terminating and the destructors of base class and intermediate class were not running, memory was being leaked.
