#include <iostream>
#include <cstdlib>
#include <ctime>
int main () {
    std::srand(std::time(0));
    int total = 0;
    int boys = 0;
    int girls = 0;
    bool girlv = false;
    bool boyv = false;
    while (!(boyv&&girlv)) {
        int r = std::rand()%2;
        if (1==r) {
            boys = boys + 1;
            boyv = true;
        }
        else {
            girls = girls + 1; 
            girlv = true;
        }
    }
    total = girls + boys; 
    std::cout << "g" << girls << "\n";
    std::cout << "b" << boys << "\n";
    std::cout << "total children: " << total;

     
}