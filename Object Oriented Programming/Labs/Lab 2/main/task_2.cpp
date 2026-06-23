#include "../headers/complex.hpp"
#include<iostream>

int main () {
complex c1(3,4);
std::cout << "complex number 1: ";
c1.display();

complex c2(1,2);
std::cout << "complex number 2: ";
c2.display();

std::cout << "sum of the complex numbers: ";
addcomplex(c1,c2).display();
}

