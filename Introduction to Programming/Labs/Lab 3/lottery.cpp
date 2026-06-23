#include <iostream>
#include <cstdlib>
#include <ctime>
int main () {
    std::srand(std::time(0));
    int a, b, c;
    a = std::rand()%8+1;
    b = std::rand()%8+1;
    c = std::rand()%8+1;
    std::cout << a << b << c << std::endl;
    int x, y, z;
    std::cout << "Enter your 3 digit number: ";
    std::cin >> x >> y >> z;
    if (a==x && b==y && c==z) {
        std::cout << "Congratulations, you won 1 million rupees";
    }
    else if (a==x&&b==z&&c==y || a==y&&b==x&&c==z || a==y&&b==z&&c==x || a==z&&b==x&&c==y || a==z&&b==y&&c==x) {
        std::cout << "Congratulations, you won 5 lac rupee";
    }
    else if (a==x||a==y||a==z||b==x||b==y||b==z||c==x||c==y||c==z) {
        std::cout << "Congratulations, you won 1 lac rupees";
    }
    else {
        std::cout << "Better luck next time";
    }
    

    
    
}