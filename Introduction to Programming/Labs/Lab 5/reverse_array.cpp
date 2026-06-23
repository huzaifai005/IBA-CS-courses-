#include<iostream>
int main () {
    std::string s[10] {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for (int i = 0; i<5; i++) {
        std::string a = s[i];
        s[i] = s[10-1-i];
        s[10-1-i] = a;
    }
    for (int i = 0; i<10; i++) {
        std::cout << s[i] << ", ";
    }
}