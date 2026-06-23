#include<iostream>
struct fraction {
    int num;
    int denom;
};

std::ostream& operator<<(std::ostream& os, const fraction& f){
os << f.num << "/" << f.denom;
return os;
}


int gcd(int a, int b) {
if (b == 0) return a;
return gcd(b, a % b);
}

void simplify (fraction& f) {
    int d =gcd(f.num, f.denom);
    f = {f.num/d, f.denom/d};
}

fraction operator*=( fraction& f1,  fraction& f2) {
    f1 = {(f1.num*f2.num), (f1.denom*f2.denom)};
    simplify(f1);
    return f1;
}

int main() {
    fraction f1 {1,2};
    fraction f2 {3,4};
    f1 *= f2;
    std::cout << f1;
}
