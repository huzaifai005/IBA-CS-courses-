#include <iostream>
#include <cmath>
int main () {
    int a, b;
    std::cout << "Enter a number a: ";
    std::cin >> a;
    std::cout << "Enter a number b: ";
    std::cin >> b;

    while (b!=0) {
        int temp = a;
        a=b;
        b = temp%b;
    }
    std::cout << a;
}