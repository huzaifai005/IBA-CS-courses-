#include<iostream>
#include<vector>
struct vector2D {
    double x;
    double y;
};

void operator*=(vector2D& v, double s) {
    v.x = v.x * s;
    v.y = v.y * s;
}

std::ostream& operator<<(std::ostream& os, const vector2D& v){
os << "(" << v.x << ", " << v.y << ")";
return os;
}

int main() {
    vector2D v1 = {1.2, 3.4};
    vector2D v2 = {5.6, 7.8};
    v1*=2.0;
    std::cout << "v1*=2.0: " << v1;
}