#include <iostream>
int main () {
    int n;
    std::cout << "Enter a postive integer: ";
    std::cin >> n;
    int i = 1;
    while (i<=n) {
        if (i%10==1&&i!=11) {
            std::cout << i << "st" << " " << "Hello" << std::endl;
        }
        else if (i%10==2&&i!=12) {
            std::cout << i << "nd" << " " << "Hello" << std::endl;
        }
        else if (i%10==3&&i!=13) {
          std::cout << i << "rd" << " " << "Hello" << std::endl;
        }
        else {
            std::cout << i << "th" << " " << "Hello" << std::endl;
        }
        i++;
    }

}