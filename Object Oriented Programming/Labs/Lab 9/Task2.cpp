#include <iostream>
#include <string>
#include <algorithm>

struct BalancedBraces {
    bool operator()(const std::string& a) const {
        int balance = 0;
        
        for (char ch : a) {
            if (ch == '{') {
                balance++;
            } else if (ch == '}') {
                if (balance == 0) {
                    return false; 
                }
                balance--;
            }
        }
        
        return balance == 0; 
    }
};

int main() {
    BalancedBraces checker;
    
    std::string a = "{{}}{}";
    std::string b = "{}{{}";
    std::string c = "}{";
    
    std::cout << "Test1 is " << (checker(a) ? "balanced" : "unbalanced") << std::endl;  
    std::cout << "Test2 is " << (checker(b) ? "balanced" : "unbalanced") << std::endl;  
    std::cout << "Test3 is " << (checker(c) ? "balanced" : "unbalanced") << std::endl;  
}