#include <iostream>
#include <string>
#include <vector>

using std::cout, std::ostream, std::string, std::vector;

char ith(int i) {
    return 'a' + i;
}

void per(const string& a, vector<bool>& b, int k) {
    if(a.size() == k) {
        cout << a << " ";
        return;
    }
    for(int i=0; i<b.size(); i++) {
        if(b[i]) continue;
        b[i] = true;
        per( a + ith(i), b, k);
        b[i] = false;
    }
}


int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    int k = 2;
    vector<bool> s(n, false);
    per("", s, k);
}