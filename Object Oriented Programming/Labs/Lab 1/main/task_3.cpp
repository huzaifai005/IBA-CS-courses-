#include<iostream>
#include "../headers/circle.hpp"

int main() {
    circle c1(2);
    std::cout << "Radius of the circle: " << c1.getRadius() << std::endl;
    
    c1.setRadius(5);

    std::cout << "New radius of the circle: " << c1.getRadius() << std::endl;

    std::cout << "Circumference of the circle: " << c1.circumference();
}