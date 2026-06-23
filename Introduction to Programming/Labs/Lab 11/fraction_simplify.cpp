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


int main() {
    fraction f {30,24};
    simplify(f);
    std::cout << f;
}
