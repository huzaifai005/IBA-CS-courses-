#include <iostream>
int main () {
    int n;
    std::cout << "Enter a number n: ";
    std::cin >>n;
    for (int a = 1;a*a*a<=n;a++) {
        for (int b = a;a*a*a+b*b*b<=n;b++) {
            int x = a*a*a+b*b*b;
            for (int c = a + 1;c*c*c<=n;c++) {
                for (int d = c;c*c*c+d*d*d<=n;d++) {
                int y = c*c*c+d*d*d;
                if (x==y&&a!=b&&a!=c&&a!=d&&b!=c&&b!=d) {
                    std::cout << a << " " << b << " " << c << " " << d;
                    }
                }
            }
        }
    }   
}