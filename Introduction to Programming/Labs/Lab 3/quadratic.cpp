#include <iostream>
#include <cmath>
int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
double discriminant = b*b - (4*a*c);
    if (discriminant>0) {
        double d = std::sqrt(discriminant);
        double root1 = (-b + d)/2*a;
        double root2 = (-b - d)/2*a;
        std::cout << "the equation has 2 real roots: " << root1 << ", " << root2;
    }
    else if (discriminant==0){
        double d = std::sqrt(discriminant);
        double root = (-b + d)/2*a;
        std::cout << "the equation has 1 real root: " << root;
    }
    else {
        std::cout << "the equation has no real roots.";
    }

}