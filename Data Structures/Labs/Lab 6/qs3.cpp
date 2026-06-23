#include <iostream>
#include <string>
#include "redblackBST.hpp"

class Mutablestring {
private:
    mutable RedBlackBST<double, char> tree;  // Add mutable
    int length;

    double generateKey(double prev, double next) {
        return (prev + next) / 2.0;
    }

public:
    Mutablestring() : length(0) {
        tree.put(0.0, '\0');  
        tree.put(1.0, '\0');  
    }
    
    char get(int i) const {
        if (i < 0 || i >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        double key = tree.select(i + 1);
        return tree.get(key);
    }
    
    void insert(int i, char c) {
        if (i < 0 || i > length) {
            throw std::out_of_range("Index out of bounds");
        }
        double prevKey = tree.select(i);      
        double nextKey = tree.select(i + 1);  
        double newKey = generateKey(prevKey, nextKey);
        tree.put(newKey, c);
        length++;
    }

    void remove(int i) {
        if (i < 0 || i >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        double keyToRemove = tree.select(i + 1);
        tree.remove(keyToRemove);
        length--;
    }

    int size() const {
        return length;
    }

    void print() const {
        for (int i = 1; i <= length; i++) {
            double key = tree.select(i);
            std::cout << tree.get(key);
        }
        std::cout << std::endl;
    }

    bool empty() const {
        return length == 0;
    }
};

int main() {
Mutablestring s;
// Insert characters to form "abcd"
s.insert(0, 'a'); s.insert(1, 'b'); s.insert(2, 'c'); s.insert(3, 'd');
std::cout << "String after inserts: "; s.print(); // Expected: abcd
// Get a character
std::cout << "s.get(2) = " << s.get(2) << std::endl; // Expected: c
// Insert in the middle
s.insert(2, 'X');
std::cout << "After insert X at pos 2: "; s.print(); // Expected: abXcd
// Remove a character
s.remove(3);
std::cout << "After remove at pos 3: "; s.print(); // Expected: abXd
// Remove first and last
s.remove(0); s.remove(s.size() - 1);
std::cout << "After removing first and last: "; s.print(); // Expected: bX
}
