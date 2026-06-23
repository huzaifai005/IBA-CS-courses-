#include<iostream>
#include<string>
 
 int str_to_int(std::string s) {
    int number;
    int final = 0;
    int mul = 1;
    
    if (s[0]=='-') {

    for(int i = s.size()-1; i >= 1; i--) {
        number = (s[i]-'0')*mul;
        final = number + final;
        mul = mul*10;
    }
    final = final *-1;
    }
    else {
    for(int i = s.size()-1; i >= 0; i--) {
        number = (s[i]-'0')*mul;
        final = number + final;
        mul = mul*10;
    }
    return (final);
 }
 return (final);
 }
 int main() {
    std::string s;
    while (std::cin >> s) {
    std::cout << str_to_int(s) << std::endl;
}
}