#include<iostream>
#include<vector>
std::vector<std::vector<int>> toMatrix(int n) {
    std::vector<std::vector<int>> a (3, std::vector<int>(3));
    int b = 0;
    for(int i = 2; i >= 0; i--) {
        for(int j = 2; j >= 0; j--) {
            if(n>0) {
            a[i][j] = n%2;
            n = n/2;
        }
        else {
            a[i][j] = 0;
        }
    }
    }
    return a;
}

void printCoinsMatrix(const std::vector<std::vector<int>>& a) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j]==0) {
                std::cout << "H ";
            }
            else if(a[i][j]==1) {
                std::cout << "T ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter a number between 0 and 511: ";
    std::cin >> n;
    std::vector<std::vector<int>> a = toMatrix(n);
    printCoinsMatrix(a);
}