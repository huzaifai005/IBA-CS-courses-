#include<iostream>
#include<vector>

int doubled(int x) {
    return x*2;
}

int squared(int x) {
    return x*x;
}

std::vector<int> transform(const std::vector<int>& values, int (*op)(int)) {
    if (values.empty()) {
        return {}; 
    }
    std::vector<int> remaining(values.begin() + 1, values.end());  
    std::vector<int> final = { op(values[0]) };           
    std::vector<int> transform2 = transform(remaining, op); 
    final.insert(final.end(), transform2.begin(), transform2.end());
    return final;
}

void print(const std::vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};

    std::cout << "Original Vector: ";
    print(a);
    std::vector<int> b = transform(a, doubled);
    std::cout << "Doubled Vector: ";
    print(b);
    std::vector<int> c = transform(a, squared);
    std::cout << "Squared Vector: ";
    print(c);
}