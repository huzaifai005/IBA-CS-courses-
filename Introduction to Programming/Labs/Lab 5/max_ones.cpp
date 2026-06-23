#include <iostream>
int main () {
    int n;
    int i;
    int b = 0;
    int a = 0;
    int count = 0;
    std::cout << "Enter a amount of numbers in array: ";
    std::cin >> n;
    int values[n];
    for (i = 0; i<n; i++) {
        std::cout << "Enter 0 or 1: ";
        std::cin >> values[i];
        }
    for (i = 0; i<n; i++) {
        if (values[i]==1) {
            count = count + 1;
            a = count;
        }
        else if (values[i]==0) {
            count = 0;
            }
            if (b<a) {
                b = a;
            }
        
    }
    std::cout << "Maximumm number of consecutives 1's are: " << b;
}