#include<iostream>
int main() {
    int a[][4] = {{9, 5, 7},
                    {1, 3, 6},
                    {5, 4, 1},
                    {0, 8, 2}};
    const int row = std::size(a);
    const int col = std::size(a[0]);
    int b[col][row] = {};
    int n = std::size(a);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = a[j][i];
        }
    }    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << b[i][j] << " ";   
        }
        std::cout << "\n";
}
}