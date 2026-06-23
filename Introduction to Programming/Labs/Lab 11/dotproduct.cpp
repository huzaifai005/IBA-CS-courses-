#include<iostream>
#include<vector>
#include<ostream>
struct vector2D {
    double x;
    double y;
};
double dot(const vector2D& v1, const vector2D& v2) {
    return v1.x*v2.x + v1.y*v2.y;

}

std::ostream& operator<<(std::ostream& os, const vector2D& v){
os << "(" << v.x << ", " << v.y << ")";
return os;
}

int main() {
    vector2D v1 = {1.2, 3.4};
    vector2D v2 = {5.6, 7.8};
    double d = dot(v1, v2); 
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "dot(v1, v2):  " << d;
}