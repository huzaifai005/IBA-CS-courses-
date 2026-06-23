#include <iostream>
int main () {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    for (int i=1; i<=n; i++){ 
        std::cout << "\n";
        
        for (int j=1; j<=n; j++){
            std::cout << "*" << " ";
           
        }
    }


}