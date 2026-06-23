#include <iostream>
int main (){
    int x; 
    std::cin >> x;
    if (x < 0){
        std::cout << "negative";
    }
    else if (x > 0) {
        std::cout << "positive";
    }
    else {
        std::cout << "zero";
    }
}