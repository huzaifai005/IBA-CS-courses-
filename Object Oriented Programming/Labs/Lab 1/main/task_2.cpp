#include<iostream>
#include "../headers/rectangle.hpp"

int main() {
    rectangle rec1(5, 10);
    std::cout << "Length of the rectangle: " << rec1.length << std::endl; 
    std::cout << "Width of the rectangle: " << rec1.width << std::endl;
    std::cout << "Area of the rectangle: " << rec1.area() << std::endl;
}