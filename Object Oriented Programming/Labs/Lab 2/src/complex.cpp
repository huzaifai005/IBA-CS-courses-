#include "../headers/complex.hpp"
#include<iostream>

complex::complex(int real, int img) 
:r(real), i(img) {}

void complex::display() {
    std::cout << r << " + " << i << "i" << std::endl;
}

complex addcomplex(complex a, complex b) {
    complex sum(a.r + b.r, a.i + b.i);
    return sum;  
}