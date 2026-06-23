#include<iostream>
double harmonic(double n) {
    if(n==0) {
        return 0;
    }
    else {
            return 1/n + harmonic (n - 1);
        }
    }

int main() {
    std::cout << harmonic(10);
}