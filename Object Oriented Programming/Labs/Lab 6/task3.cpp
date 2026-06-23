#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<vector>


class Shape {
public: 
    virtual double computePerimeter() = 0;
    virtual ~Shape() {};
};

class Circular : public Shape {
private:
    double r;

public: 
    Circular(double radius) : r(radius) {
        std::cout << "making a circle with radius " << r << std::endl;
    }

    double computePerimeter() override {
        double p = 2* M_PI * r;
        return p;
    }
};

class Rectangular : public Shape {
private: 
    double l;
    double w;

public:
    Rectangular(double length, double width) : l(length), w(width) {
        std::cout << "Making a rectangle with length " << l << " and width " << w << std::endl;
    }
    
    double computePerimeter() override {
        double p = 2 * (l + w);
        return p;
    }
};

class Triangular : public Shape {
private: 
    double a;
    double b;
    double c;

public:
    Triangular(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {
        std::cout << "Making a triangle with sides " << a << ", " << b << ", " << c << std::endl;
    }
    
    double computePerimeter() override {
        double p = a + b + c;
        return p;
    }
};

class Polygonal : public Shape {
private: 
    double a;
    double b;
    double c;
    double d;

public:
    Polygonal(double side1, double side2, double side3, double side4) : a(side1), b(side2), c(side3), d(side4) {
        std::cout << "Making a polygon with sides " << a << ", " << b << ", " << c << ", " << d << std::endl;
    }
    
    double computePerimeter() override {
        double p = a + b + c + d;
        return p;
    }
};

int main() {
    std::vector<Shape*> shapes = {new Circular(5), new Rectangular(4, 6), new Triangular(3, 4, 5), new Polygonal(2, 3, 4, 5)};

   
    for (Shape* s : shapes) {
        std::cout << "perimeter = " <<s->computePerimeter() << std::endl;  
  
  
    }
    for (Shape* s : shapes) {
        delete s;
    }
}