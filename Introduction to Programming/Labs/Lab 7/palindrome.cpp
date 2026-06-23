#include<iostream>
int main() {
    std::string p = {};
     std::string temp = {};
    std::cout << "Enter a word: ";
    std::cin >> p;
    int x = p.size();
    for (int i = x-1; i >= 0; i--) {
        temp = temp + p[i];
    }
    if (temp==p) {
        std::cout << "The given string is a palindrome.";
    }
    else {
        std::cout << "The given string is not a palindrome.";
    }
}