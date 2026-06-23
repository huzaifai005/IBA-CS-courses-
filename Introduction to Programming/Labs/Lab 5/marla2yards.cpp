#include <iostream>
int main () {
    int marla = 5;
    double square;
    for (int i = 0; i<6; i++) {
        square = marla * 30.25;
        std::cout << marla << " marla " << "= " << square << " square yards " << std::endl;
        square = 0;
        marla = marla + 5;
    }
}