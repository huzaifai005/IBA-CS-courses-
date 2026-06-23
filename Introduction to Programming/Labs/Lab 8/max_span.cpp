#include<iostream>
#include<vector>
int max_span(std::vector<int> v) {
    int max = 0;
    int span = 1;
    for(int i = 0; i < size(v); i++) {
        for(int j = i + 1; j < size(v); j++) {
            if (v[i]==v[j]) {
                span = j - i + 1;
            }
            if(span>max) {
                max = span;
            }
        }
    }
    return max;
}
int main() {
    std::vector<int> v1 = {1, 2, 1, 1, 3};
    std::vector<int> v2 = {1, 4, 2, 1, 4, 1, 4};
    std::vector<int> v3 = {1, 4, 2, 1, 4, 4, 4};
    std::cout << "Max span is: " << max_span(v3);

}
