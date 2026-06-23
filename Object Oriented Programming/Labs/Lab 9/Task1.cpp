#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

struct Element {
    int atomicNumber;
    std::string name;
    std::string symbol;
};

struct Sort {
    int smallestAtomicNum;
    
    Sort(int min = 0) : smallestAtomicNum(min) {}
    
    bool operator()(const Element& a, const Element& b) const {
        if (a.atomicNumber < smallestAtomicNum && b.atomicNumber >= smallestAtomicNum) return false;
        if (a.atomicNumber >= smallestAtomicNum && b.atomicNumber < smallestAtomicNum) return true;
        if (a.atomicNumber != b.atomicNumber) {
            return a.atomicNumber < b.atomicNumber;
        }
        return a.name < b.name;
    }
};

struct Length {
    bool operator()(const Element& c) const {
        return c.name.length() > 5;
    }
};

int main() {
    std::vector<Element> elements = {
        {1, "Hydrogen", "H"},
        {20, "Calcium", "Ca"},
        {14, "Silicon", "Si"},
        {4, "Beryllium", "Be"},
        {19, "Potassium", "K"},
        {11, "Sodium", "Na"},
        {13, "Aluminum", "Al"},
        {8, "Oxygen", "O"},
        {17, "Chlorine", "Cl"},
        {10, "Neon", "Ne"}
    };

    int minAtomicNum;
    std::cout << "Enter minimum atomic number for filtering: ";
    std::cin >> minAtomicNum;
    
    Sort sorter(minAtomicNum);
    std::sort(elements.begin(), elements.end(), sorter);
    
    std::cout << std::endl << "Sorted Elements (Atomic Number >= " << minAtomicNum << "):" << std::endl;
    for (const auto& d : elements) {
        if (d.atomicNumber >= minAtomicNum) {
            std::cout << d.atomicNumber << ": " << d.name << " (" << d.symbol << ")" << std::endl;
        }
    }
    
    Length filter;
    int count = std::count_if(elements.begin(), elements.end(), filter);
    std::cout << std::endl << "Number of elements with names longer than 5 characters: " 
              << count << std::endl;
    
    std::vector<std::string> uppercase;
    std::transform(elements.begin(), elements.end(), std::back_inserter(uppercase),
        [](const Element& e) {
            std::string upper;
            for (char c : e.symbol) {
                upper += toupper(c);
            }
            return upper;
        });
    
    std::cout << std::endl << "Uppercase Symbols:" << std::endl;
    for (const auto& sym : uppercase) {
        std::cout << sym << " ";
    }
    std::cout << std::endl;
}