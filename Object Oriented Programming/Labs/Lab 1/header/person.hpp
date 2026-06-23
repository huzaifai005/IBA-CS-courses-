#pragma once

#ifndef _PERSON_H  
#define _PERSON_H
#include<string>

class person {
public:
    person(std::string n, int a);
    
    void print();

private:
std::string name;
int age;

};
#endif