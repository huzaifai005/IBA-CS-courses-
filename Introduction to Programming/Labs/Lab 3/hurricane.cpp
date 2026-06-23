#include <iostream>
int main(){
    int x;
    std::cin >> x;
    if (x<74) {
        std::cout << "no hurricane";
    }
    else {
        if (x>=74&&x<=95) {
            std::cout << "category 1 hurricane";
        }
        else if (x>=96&&x<=110) {
            std::cout << "category 2 hurricane";
        }
        else if (x>=111&&x<=130) {
            std::cout << "category 3 hurricane";
        }
        else if (x>=131&&x<=155) {
            std::cout << "category 4 hurricane";
        }
        else if (x>156) {
            std::cout << "category 5 hurricane";
        }
    }
}
    
    
     
    
