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

bool operator==(const fraction& f1,const fraction& f2) {
    fraction temp = f1;
    fraction temp2 = f2;
    simplify(temp);
    simplify(temp2);
    if(temp.num==temp2.num&&temp.denom==temp2.denom) {
        return true;
    }
    return false;
}

int main() {
    fraction f1 {1,2};
    fraction f2 {2,4};
    if(f1==f2) {
        std::cout << "f1 and f2 are equal.";
    }
    else {
        std::cout << "f1 and f2 are not equal.";
    } 
}
