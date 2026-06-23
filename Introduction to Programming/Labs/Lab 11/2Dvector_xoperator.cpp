#include<iostream>
#include<vector>
struct vector2D {
    double x;
    double y;
};

vector2D operator*(const vector2D& v, double s) {
    vector2D a;
    a.x = v.x * s;
    a.y = v.y * s;
    return a;
}

std::ostream& operator<<(std::ostream& os, const vector2D& v){
os << "(" << v.x << ", " << v.y << ")";
return os;
}

int main() {
    vector2D v1 = {1.2, 3.4};
    vector2D v2 = {5.6, 7.8};
    const vector2D v3 = v1*2.0; 
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v3 = v1 * 2.0: " << v3;
}