#include<iostream>
#include<vector>
int findMax1(const std::vector<int>& a, int n) {
    if(n==1) {
        return a[0];
    }
    int m = findMax1(a, n - 1);
    if(a[n - 1] > m) {
        return a[n - 1];
    }
    else {
        return m;
    }
}

int findMax(const std::vector<int>& a) {
    return findMax1(a, a.size());
}


int main() {
    std::vector<int> a = {6, 8, 5, 2, 0, 7, 1};
    std::cout << "The maximum value in this array is: " << findMax(a);
}
