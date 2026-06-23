#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <string>
#include <vector>
#include <list>
#include <cmath>

class HashTable {
public:
    HashTable(int initialSize);

    bool insert(const std::string& word);

    bool contains(const std::string& word) const;

    void rehash();

private:
    std::vector<std::list<std::string>> table;
    int arraySize;      
    int currentSize;    
    
    const double MAX_LOAD_FACTOR = 0.7; 

    unsigned long hash(const std::string& word) const;

    int getNextPrime(int n) const;

    bool isPrime(int n) const;
};

#endif 