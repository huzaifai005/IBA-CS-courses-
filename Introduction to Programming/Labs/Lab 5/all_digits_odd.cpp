#include <iostream>
int main () {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    bool isOdd = true;
    int a = n;
    while (a!=0) {
        if (a%2==0) {
            isOdd = false;
            break;
        }
        a = a/10;
    }
    if (isOdd) {
        std::cout << "true";
    } 
    else {
        std::cout << "false";
    }

        

}