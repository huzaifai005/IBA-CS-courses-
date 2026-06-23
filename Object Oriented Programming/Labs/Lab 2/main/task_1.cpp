#include "../headers/dynamicint.hpp"
#include<iostream>

int main() {
    dynamicint n1(5);
    dynamicint n2(10);
    
    n2 = n1;

    std::cout << "original value: " << n1.getint() << std::endl;
    std::cout << "copied value (using the assignment operator): " << n2.getint() << std::endl;
    std::cout << "now modifying my original value." << std::endl;
    n1.setint(10);
    std::cout << "original value after modification: " << n1.getint() << std::endl;
    std::cout << "copied value after modification: " << n2.getint() << std::endl;
    std::cout << "now deleting the original value." << std::endl;
    n1.~dynamicint();
    std::cout << "copied value after deleting: " << n2.getint() << std::endl;

}