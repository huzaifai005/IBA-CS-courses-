#include <iostream>
#include <algorithm>

int main()
{
int x,y,z;
    std::cout << "enter 3 values: ";
    std::cin >> x >> y >> z;

int small;
    small = std::min (x,y);
int s;
    s = std::min (small,z);
int big;
    big = std::max (x,y);
int b;
    b = std::max (big,z);
int total = x + y + z;
int middle = total - s - b;
std::cout << "ascending order: " << s << " " << middle << " " << b;

} 
