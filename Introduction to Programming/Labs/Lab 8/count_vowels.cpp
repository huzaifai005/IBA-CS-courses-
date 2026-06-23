#include<iostream>
int count_vowels(std::string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
            count = count + 1;
        }
    }
    return count;
}
int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline (std::cin, str);
    std::cout << count_vowels(str);

}