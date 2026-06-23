#include <iostream>
int main () {
    int n;
    int i;
    int j;
    int tru;
    int fal;
    std::cout << "Enter the amount of numbers in array: ";
    std::cin >> n;
    int values[n];
    for (i = 0; i<n; i++) {
        std::cout << "Enter value: ";
        std::cin >> values[i];
        }
    for (i = 0; i<n; i++) {
        int t;
        t = values[i];
        for ( j = 0; j<n; j++) {
            if(t==values[j] && i!=j) {
                tru = tru + 1;
                break;
            }
            else {
                fal = fal + 1;
            }
        }
    }
    if (tru>=1) {
        std::cout << "true";
    }
    else if (tru<1) {
       std::cout << "false";
    }
}
