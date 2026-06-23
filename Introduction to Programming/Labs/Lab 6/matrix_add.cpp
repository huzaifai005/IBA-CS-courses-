#include<iostream>
int main() {
    int a [][4] = {{2, 5, 7, 1},
                    {1, 3, 6, 1},
                    {5, 4, 1, 3}};
    int b [][4] = {{1, 9, 5, 0},
                    {7, 1, 5, 4},
                    {3, 4, 2, 8}};
    int c [][4] = {};
    int n = std::size(a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           std::cout << c[i][j] << " ";
        }
        std::cout << "\n";
    }
}
