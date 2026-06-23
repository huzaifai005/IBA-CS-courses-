#include<iostream>
int main() {
    long double fib[100] = {};
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < 100; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int i = 0; i < 100; i++) {
        std::cout << fib[i] << " ";
    }
    
}
//using long double because tried with long long but the numbers were not printing correctly after the 91st number.