#include<iostream>
#include<vector>
bool can_balance(std::vector<int> v) {
    int totalsum = 0;
    int leftsum = 0;
    bool check = false;
    for(int i = 0; i < size(v); i++) {
    totalsum = totalsum + v[i];
    }
    for (int j = 0; j < size(v); j++) {
        leftsum = leftsum + v[j];
        if (leftsum==(totalsum - leftsum)) {
            check = true;
            break;
        }
    }
return check;
}
int main() {
    std::vector<int> v1 = {4, 1, 1, 1, 1};
    std::cout << can_balance(v1);
}
