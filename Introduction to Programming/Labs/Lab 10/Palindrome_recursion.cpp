#include<iostream>
bool isPalindrome(const std::string& p) {
    if(p.size() <= 1) {
        return true;
    }
    if(p[0]!=p[p.size()-1]) {
        return false;
    }
    else {
        return isPalindrome(p.substr(1, p.size() - 2));
    }
}
int main() {
    std::string p;
    std::cin >> p;
    if(isPalindrome(p)) {
        std::cout << "The given string is a palindrome,";
    }
        else {
            std::cout << "The given string is not a palindrome.";
        }
    }