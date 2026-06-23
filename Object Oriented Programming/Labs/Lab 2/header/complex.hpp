#ifndef COMPLEX_H
#define COMPLEX_H

class complex {
public: 
    complex (int real, int img);
    
    void display();

    friend complex addcomplex(complex a, complex b);

private:
int r;
int i;
};
#endif