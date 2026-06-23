#include<iostream>
#include<vector>
struct vector2D {
    double x;
    double y;
};

vector2D add(const vector2D& v1, const vector2D& v2) {
    vector2D a;
    a.x = v1.x + v2.x;
    a.y = v1.y + v2.y;
    return a;
}

std::ostream& operator<<(std::ostream& os, const vector2D& v){
os << "(" << v.x << ", " << v.y << ")";
return os;
}

int main() {
    vector2D v1 = {1.2, 3.4};
    vector2D v2 = {5.6, 7.8};
    const vector2D v3 = add(v1, v2);
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3=add(v1,v2): " << v3 << std::endl;
}