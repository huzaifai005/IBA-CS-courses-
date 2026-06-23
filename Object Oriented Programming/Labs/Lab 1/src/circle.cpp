#define _USE_MATH_DEFINES
#include<cmath>
#include "../headers/circle.hpp"

circle::circle(float r)
    : radius(r) {}

void circle::setRadius(float r) {
    radius = r;
}

float circle::getRadius() {
    return radius;
}

float circle::circumference() {
    float circumference = 2 * M_PI * radius;
    return circumference;
}
