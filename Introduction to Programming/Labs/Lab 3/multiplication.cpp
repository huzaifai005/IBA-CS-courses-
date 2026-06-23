#include <iostream>
int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    int i = 1;
    int multiple;
    multiple = 0;
    while (i<=10) {
        multiple = n*i;
        std::cout << n << " x " << i << " = " << multiple << std::endl;
        i = i + 1;
    }
}