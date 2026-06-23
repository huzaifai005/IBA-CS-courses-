#include <iostream>
#include <cstdlib>
#include <ctime>

int main ()
{   std::srand(std::time(0));
    int x,y,z;
    x = std::rand();
    y = std::rand();
    z = std::rand();
    std::cout << x << " " << y << " " << z << '\n';
    
float avg = (x + y + z)/3;
    std::cout << "average: " << avg << '\n';

int small; 
    small = std::min (x,y);
int s; 
    s = std::min (small,z);           
    std::cout << "min: " << s << '\n';

int big;
    big = std::max (x,y);
int b;
    b = std::max (big,z);
    std::cout << "max: " << b << '\n';    
}
