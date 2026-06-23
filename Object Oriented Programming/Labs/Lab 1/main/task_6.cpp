#include "../headers/dice.hpp"
#include<iostream>
#include<cstdlib>
#include<ctime>


int main () {
    std::srand(std::time(0));
    int a = rand()%94+6;
    dice d1(a);

    std::cout << "rolling the " << d1.getSides() << "-sided dice: " << d1.rolldice() << std::endl;

    int b = rand()%94+6;
    dice d2(b);

    std::cout << "rolling the " << d2.getSides() << "-sided dice: " << d2.rolldice() << std::endl;

    int c = rand()%94+6;
    dice d3(c);

    std::cout << "rolling the " << d3.getSides() << "-sided dice: " << d3.rolldice() << std::endl;

    std::cout << "Number of sides of the " << d3.getSides() << "-sided dice: " << d3.getSides() << std::endl;

    std::cout << "Total number of sides created: " << dice::getCount();
}