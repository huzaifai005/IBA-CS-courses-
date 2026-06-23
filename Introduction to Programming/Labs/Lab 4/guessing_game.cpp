#include <iostream>
#include <ctime>
int main () {
std::srand(std::time(0));
int x;
x = std::rand()%100+1;
std::cout << x << std::endl;
int n;
std::cout << "Enter a number: ";
std::cin >> n;
while (n!=x) {
    if (n>x) {
        std::cout << "Too high" << std::endl;
        std::cout << "Enter a new number: ";
        std::cin >> n;    
    }
    else if (n<x) {
        std::cout << "Too low" << std::endl;
        std::cout << "Enter a new number: ";
        std::cin >> n;
    }
}
std::cout << "Congratulations, your guess is correct.";
}

   
    

    

