#include <iostream>
int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    float i = 1;
    double sum;
    sum = 0;
    while (i<=n) {
        sum = sum + 1/i;
        i = i + 1;
        }
    std::cout << sum;
    }