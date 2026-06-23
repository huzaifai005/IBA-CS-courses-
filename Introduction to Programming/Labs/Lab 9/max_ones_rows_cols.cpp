#include<iostream>
#include<vector>
#include<ctime>
std::vector<std::vector<int>> genRandomMatrix(int m, int n) {
    std::vector<std::vector<int>> a (m, std::vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = rand()%2;
            }
        }
    return a;
}

void printMatrix(const std::vector<std::vector<int>>& a) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int findMaxOnesRow(const std::vector<std::vector<int>>& a) {
    int count = 0;
    int final = 0;
    int temp = 0;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[0].size(); j++) {
            if (a[i][j]==1) {
        count = count + 1;
    }
     }
     if (count>temp) {
        temp = count;
        final = i;
    }
    count = 0;
}
return final;
}

int findMaxOnesCol(const std::vector<std::vector<int>>& a) {
    int count = 0;
    int final2 = 0;
    int temp = 0;
    for(int j = 0; j < a[0].size(); j++) {
        for(int i = 0; i < a.size(); i++) {
            if (a[i][j]==1) {
        count = count + 1;
    }
     }
     if (count>temp) {
        temp = count;
        final2 = j;
    }
    count = 0;
}
return final2;
}

int main() {
    std::srand(std::time(0));
    
    std::vector<std::vector<int>> a = genRandomMatrix(4,4);
    printMatrix(a);
    std::cout << std::endl;
    int maxRowIndex = findMaxOnesRow(a);
    int maxColIndex = findMaxOnesCol(a);
    std::cout << "The Largest Row Index: " << maxRowIndex+1 << std::endl;
    std::cout << "The Largest Column Index: " << maxColIndex+1 << std::endl;
}