#include<iostream>
void writeChars(int n) {
    if(n==1) {
        std::cout << "*";
    }
    else if(n==2) {
            std::cout << "**";
    }
    else {
        if(n>2 && n<7) {
            std::cout << "<";
            writeChars(n - 2);
            std::cout << ">";
        }
        else {
            std:: cout << "<";
            writeChars(n - 2);
            std::cout << ">>>";
        }
    }
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    writeChars(n);
}