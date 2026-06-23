#include<iostream>
#include "../headers/instanceCounter.hpp"

int main(){
instanceCounter c1;
instanceCounter c2;

std::cout << "Number of instances created: " << instanceCounter::getCount();
}