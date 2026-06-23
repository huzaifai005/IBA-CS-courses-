#include<iostream>
struct fraction {
    int num;
    int denom;
};

std::ostream& operator<<(std::ostream& os, const fraction& f){
os << f.num << "/" << f.denom;
return os;
}

int main() {
    fraction f {1,2};
    std::cout << f;
}
