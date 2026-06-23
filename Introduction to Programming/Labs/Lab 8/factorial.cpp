#include<iostream>
long long factorial(long long n) {
    int fac = 1;
    int i = n;
   if(n>=1) {
       while (i>0){
        fac = i * fac;
        i--;
        }
    }
    else if (n = 0) {
        fac = 1;
    }
    return fac;
}
int main () {
    long long n;
    std::cout << "Enter an integer n: ";
    std::cin >> n;
    std::cout << factorial(n);
}