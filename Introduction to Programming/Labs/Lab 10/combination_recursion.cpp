#include <iostream>
#include <string>
#include <vector>

using std::cout, std::string, std::vector;
char ith(int i) {
    return 'a' + i;
}


void Comb(const string& a, int start, int n) {
    if (!a.empty()) {
        cout << a << " ";
    }

    for (int i = start; i < n; ++i) {
        Comb(a + ith(i), i + 1, n);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    std::cin >> n; 
    
    Comb("", 0, n);
}
