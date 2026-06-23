#include<iostream>
#include<vector>
#include<cmath>

std::vector<int> notalone(std::vector<int> a, int  y) {
    for (int i = 1; i < a.size() - 1; i++) {
        if (a[i]==y && a[i-1]!=y && a[i+1]!=y) {
            a[i] = std::max(a[i-1],a[i+1]);
        }
    }
    return a;
}
int main () {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {1, 2, 3, 2, 5, 2};
    v2 = notalone(v2, 2);
    for(int i = 0; i < v2.size(); i++) {
        std::cout << v2[i] << " ";
    }
}