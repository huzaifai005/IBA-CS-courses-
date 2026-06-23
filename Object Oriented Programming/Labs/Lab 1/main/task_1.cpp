#include<iostream>
#include "../headers/student.hpp"

int main() {
    student student1; 
    std::cout << "Enter student's name: ";
    std::cin >> student1.name;
    std::cout << "Enter student's ERP: ";
    std::cin >> student1.ERP;
    std::cout << "Enter student's grade: ";
    std::cin >> student1.grade;
 
    std::cout << std::endl << "student's name: " << student1.name << std::endl; 
    std::cout << "student's ERP: " << student1.ERP << std::endl;
    std::cout << "student's grade: " << student1.grade << std::endl; 

}