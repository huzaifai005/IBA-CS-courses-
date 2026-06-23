#include<iostream>
bool isValid(std::string& p) {
      int count = 0;
            int count1 = 0;
    if (p.size()<10) {
        return false;
    }
        for(int i = 0; i < p.size(); i++) {
            if(!(isalpha(p[i])||isdigit(p[i]))) {
                return false;
                break;
            }
            if(isalpha(p[i])) {
                count = count + 1;
            }
            if(isdigit(p[i])) {
                count1 = count1 + 1;
            }
        }
        if (count < 1||count1 < 2) {
            return false;
        }
    return true;
}

int main () {
    std::string p;
    std::cout << "Enter your password: ";
    std::cin >> p;
    if(isValid(p)) {
        std::cout << "Your password is valid.";
    }
    else {
        std::cout << "Your password is invalid.";
    }
}