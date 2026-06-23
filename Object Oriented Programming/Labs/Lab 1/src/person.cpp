#include "../headers/person.hpp"
#include<iostream>
person::person(std::string n, int a)
    : name(n), age(a) {}

void person::print() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}