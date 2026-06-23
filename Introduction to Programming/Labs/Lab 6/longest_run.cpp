#include <iostream>
int main () {
    int n;
    int i;
    int b = 0;
    int a = 0;
    int c = 0;
    int d = 0;
    int count = 1;
    std::cout << "Enter a amount of numbers in array: ";
    std::cin >> n;
    int values[n];
    for (i = 0; i<n; i++) {
        std::cout << "Enter a number: ";
        std::cin >> values[i];
        }
    for (i = 0; i<n; i++) {
        if (values[i]==values[i+1]) {
            c = values[i];
            count = count + 1;
            a = count;
        }
        else if (values[i]!=values[i+1]) {
            count = 1;
            }
            if (b<a) {
                b = a;
                d = c;
                c = 0;
            }
        
    }
    std::cout << b << " consecutive " << d << "'s";
}