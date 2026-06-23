#include<iostream>
double pi(int n) {
    double x = 0;
    double a = 1;
    for(int i = 1; i < n; i++) {
        if(i%2==0) {
            x = x - (1.0)*4/a;
        }
        else if (i%2==1) {
            x = x + (1.0)*4/a;
        }
        a = a + 2;
    }
    return x;
}

int main () {
    std::cout << pi(200000);
}