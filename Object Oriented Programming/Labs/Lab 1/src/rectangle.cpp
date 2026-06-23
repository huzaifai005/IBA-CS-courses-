#include "../headers/rectangle.hpp"

rectangle::rectangle(const int len,const int wid)
    : length(len), width(wid) {}

int rectangle::area() {
    int area = length * width;
    return area;
}
