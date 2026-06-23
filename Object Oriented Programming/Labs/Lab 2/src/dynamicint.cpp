#include "../headers/dynamicint.hpp"

dynamicint::dynamicint(int n) { 
    num = new int(n); 
}
dynamicint::dynamicint(const dynamicint& other) {
    num = new int(*other.num);
}
void dynamicint::setint(int n) {
    *num = n;
}

int dynamicint::getint() {
    return *num; 
}

dynamicint::~dynamicint() {
    delete num;
    num = nullptr;
}
dynamicint& dynamicint::operator=(const dynamicint& other) {
    if(this != &other) {
        delete num;
        num = new int(*other.num);
    }
    return *this;
}