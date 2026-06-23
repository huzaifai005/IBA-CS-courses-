    //Huzaifa Iqbal 31563
#include <iostream>
#include <ctime>
int main () {
    std::srand(std::time(0));
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    int a;
    int x = 0;
    int y = 0;
    std::cout << "(" << x << ", " << y << ")" << std::endl;
    for (int c = 1; c<=n; c++) {
        a = std::rand()%4+1;
        if (a==1) {
            x = x + 1;
        }
            else if (a==2) {
                x = x - 1;
            }
                else if (a==3) {
                        y = y + 1;
                    }
                        else if (a==4) {
                            y = y - 1;
                        }
    std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
    int square;
    square = x*x+y*y;
    std::cout << "Squared distance: " << square;
}