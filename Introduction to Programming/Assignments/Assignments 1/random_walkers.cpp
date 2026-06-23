    //Huzaifa Iqbal 31563
#include <iostream>
#include <ctime>
int main () {
    std::srand(std::time(0));
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    double trials;
    std::cout << "Enter number of trials: ";
    std::cin >> trials;
    int a;
    double m = 0;
    int x = 0;
    int y = 0;
    for (int t = 1; t<=trials; t++) {
        int x = 0;
        int y = 0;
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
    }
    double square;
    square = x*x+y*y;
    m = m + square;
    }
    double mean;
    mean = m/trials;
    std::cout << "Mean squared distance = " <<  mean;
}
