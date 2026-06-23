#include <iostream>
int main () {
    int n;
    int i;
    int count = 0;
    std::cout << "Enter a amount of numbers in array: ";
    std::cin >> n;
    int values[n];
    for (i = 0; i<n; i++) {
        std::cout << "Enter value: ";
        std::cin >> values[i];
        }
    for (i = 0; i<n; i++) {
        if (values[i]%2==0) {
         count = count + 1;
}

    }
    std::cout << "Count of even number: " << count;

    }


