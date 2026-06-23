#include<iostream>
#include<vector>
bool vector_eq(std::vector<int> v1, std::vector<int> v2) {
    bool isequal = true;
    if (size(v1)==size(v2)) {
        for (int i = 0; i < size(v1); i++) {
            if(v1[i]!=v2[i]) {
                isequal = false;
                break;
            }
            else {
                isequal = true;
            }
        }
    }
    else {
        isequal = false;
    }
    return isequal;
}
int main() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 5};
std::cout << vector_eq(vec1, vec2);
}