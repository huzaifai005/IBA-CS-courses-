#include<iostream>
#include<ctime>
int main () {
    std::srand(std::time(0));    
    int x;
    int n;
    std::cout << "Enter the size of array: "; 
    std::cin >> n;
    int sort[n] {};
    for (int i = 0; i < n; i++) {
        sort[i] = std::rand()%99;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sort[i]>sort[j]) {
                x = sort[i];
                sort[i] = sort[j];
                sort[j] = x;
            }
        }
    }
    for (int i = n-1; i >= 0 ; i--) {
        std::cout << sort[i] << " ";
    }
}

