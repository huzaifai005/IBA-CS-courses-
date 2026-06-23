#include<iostream>
int main() {
    int rot[6] = {1,2,3,4,5,6};
    std::cout << "Enter the elements you want the array to be rotated by: ";
    int n;
    std::cin >> n;
    int temp[6] = {};
    for (int i = 0; i < n; i++) {
        temp[i] = rot[i];
    }
    for (int i = 0; i < 6-n; i++) {
        rot[i] = rot[i+n];
        std::cout << rot[i] << " ";
    }
    for (int i = 6 - n; i < 6; i++) {
        rot[i] = temp[i - (6 - n)];
        std::cout << rot[i] << " ";
    }
    
}