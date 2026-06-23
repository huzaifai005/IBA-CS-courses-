#include<iostream>
#include<vector>
bool rowsCheck(const std::vector<std::vector<int>> a) {
    for(int i = 0; i < 9; i++) {
        std::vector<bool> rows(10, false);
        for(int j = 0; j < 9; j++) {
            if(a[i][j]!=0) {
                if(rows[a[i][j]]) {
                    return false;
                }
                rows[a[i][j]] = true;           
            }
        }
    }
    return true;
}

bool colsCheck(const std::vector<std::vector<int>> a) {
    for(int i = 0; i < 9; i++) {
        std::vector<bool> cols(10, false);
        for(int j = 0; j < 9; j++) {
            if(a[i][j]!=0) {
                if (cols[a[i][j]]) {
             return false;
                }
                cols[a[i][j]] = true;
            }
        }
    }
    return true;
}

bool blockCheck(const std::vector<std::vector<int>> a) {
    for (int blockrow = 0; blockrow < 9; blockrow += 3) {
        for (int blockcol = 0; blockcol < 9; blockcol += 3) {
            std::vector<bool> check(10, false);
            for (int i = blockrow; i < blockrow + 3; i++) {
                for (int j = blockcol; j < blockcol + 3; j++) {
                    if(a[i][j]!=0) {
                        if(check[a[i][j]]) {
                            return false;
                        }
                        check[a[i][j]] = true;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> a = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9} };
        if (rowsCheck(a)&&colsCheck(a)&&blockCheck(a)) {
            std::cout << "valid soduko solution." << std::endl;
        }
        else {
            std::cout << "Invalid soduko solution." << std::endl;
        }
}

