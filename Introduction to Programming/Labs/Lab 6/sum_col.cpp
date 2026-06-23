#include<iostream>
int main () {
    int a[3][3] = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};
    int c = 0;
    int j = 1;
    for (int i = 0; i<3; i++) {
            c = c + a[i][j]; 
        }
            std::cout << c; 
    }