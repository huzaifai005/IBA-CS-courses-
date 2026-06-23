#include <iostream>
#include <cstdlib>
#include <ctime>

int main () {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    int i = 1; 
    int sum;
    sum = 0;
    while (i<=n) {
        sum = sum + i;
        i = i + 1;
    }
    std::cout << "sum: ";
    std::cout << sum;
}