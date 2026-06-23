#include<iostream>
int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);
    int a = 0;
    for (char c : s) {
        if (c =='(') {
            a = a+1;
            std::cout << "level" << " " << a << std::endl;
        }
        else if (c == ')') {
            a = a-1;
            if (a<0) {
                break;
            }
            else  {
            std::cout << "level" << " " <<  a << std::endl;
            }
        }
}
if (a<0) {
    std::cout << "Unmatched ')'";
}
else if (a==0) {
    std::cout << "Well-bracketed expression";
}
}