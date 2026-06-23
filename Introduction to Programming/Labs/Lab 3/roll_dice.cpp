#include <iostream>
#include <cstdlib>
#include <ctime>
int main (){
    std::srand(std::time(0));
    int x;
    x = std::rand()%6+1;
    std::cout << x << "\n";
}
