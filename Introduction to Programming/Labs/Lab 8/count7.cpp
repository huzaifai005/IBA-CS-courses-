#include<iostream>
int count7(int x) {
    int count = 0;
    while(x>0){
        if (x%10==7) {
            count = count + 1;
        }
        x = x/10;
    }
    return count;
}
int main() {
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;
    std::cout << "Number of consecutive 7's are: " << count7(x);
}