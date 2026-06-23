#include <iostream>
#include <cmath>
#include <string>
int main () {
    std::string bin;
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    int b;
    int c;
    
    while (a!=0) {
        b=a%2;
        c=a/2;
        a=c;
        bin = std::to_string(b) + bin;
    }
    std::cout << bin;

}