
#ifndef DYNAMICINT_H
#define DYNAMICINT_H

class dynamicint {

public:
    dynamicint(int n);

    dynamicint(const dynamicint& other);

    void setint(int n);
    int getint();

    dynamicint& operator=(const dynamicint& other);

    ~dynamicint();

private:
    int* num;
};

#endif