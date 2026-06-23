#include "redblackBST.hpp"
#include<iostream>
#include <cmath> 
#include <vector>

class Svector {
private: 
RedBlackBST<int, double> tree;

public:
Svector() = default;

void set(int i, double x) {
    if (x == 0) {
        return;
    }
    tree.put(i, x);
}

double get(int i) const {
    if(tree.contains(i)) {
        return tree.get(i);
    }
    else {
        return 0.0;
    }
}

double& operator[](int i) {
    static double data = 0.0;
    if(tree.contains(i)) {
        data = tree.get(i);
        return data;
    }
    else {
        tree.put(i, 0.0);
        data = tree.get(i);
        return data;
    }
}

double dot(const Svector& that) const {
    double result;
    std::vector<int> indices;
    tree.keys(indices);
    for(int key : indices) {
        result += tree.get(key) * that.get(key);
    }
    return result;
}

double norm() const {
    double squaresum;
    std::vector<int> indices;
    tree.keys(indices);
    for(int key : indices) {
        squaresum += tree.get(key) * tree.get(key);
    }
    double squareroot = std::sqrt(squaresum);
    return squareroot;
}

Svector add(const Svector& that) const {
    Svector result;
    std::vector<int> indices;
    tree.keys(indices);
    for(int key : indices) {
        result.set(key, tree.get(key));
    }
    std::vector<int> thatIndices;
    that.tree.keys(thatIndices);
    for(int key : thatIndices) {
        double sum = result.get(key) + that.get(key);
        result.set(key, sum);
    }
    return result;
}

void scale(double alpha) {
    std::vector<int> indices;
    tree.keys(indices);
    for(int key : indices) {
        tree.put(key, tree.get(key) * alpha);
    }
}

void print() const {
std::vector<int> indices;
tree.keys(indices);
    
std::cout << "{";
    for (size_t i = 0; i < indices.size(); i++) {
        std::cout << "(" << indices[i] << "," << tree.get(indices[i]) << ")";
        if (i < indices.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}";
}
};

int main() {
Svector v1, v2;
v1.set(1, 3.0); v1.set(3, 4.0); v1.set(10, 5.0);
std::cout << "v1 = "; v1.print();
v2.set(1, 2.0); v2.set(2, 7.0); v2.set(3, 1.0);
std::cout << "v2 = "; v2.print();
std::cout << "v1.get(2) = " << v1.get(2) << " (should be 0)\n";
std::cout << "v1 . v2 = " << v1.dot(v2) << "\n";
std::cout << "||v1|| = " << v1.norm() << "\n";
Svector v3 = v1.add(v2); std::cout << "v1 + v2 = "; v3.print();
v1.scale(2.0); std::cout << "2 * v1 = "; v1.print();
// test removing entry by setting to 0
v1.set(3, 0.0); std::cout << "After setting v1[3] = 0: "; v1.print();
}
