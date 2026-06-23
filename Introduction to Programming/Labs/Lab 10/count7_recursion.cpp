#include<iostream>
int count7(int n) {
    int count = 0;
    if(n==0) {
    return 0;
    }
    if(n%10==7) {
        return 1 + count7(n/10);
    }
    else {
        return count7(n/10);
    }
}

int main() {
    std::cout << count7(717);
}