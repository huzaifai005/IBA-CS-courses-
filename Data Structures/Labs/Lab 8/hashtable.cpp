#include "hashtable.hpp"
#include <iostream>
#include <algorithm> 
#include <utility>   

bool HashTable::isPrime(int p) const {
    if ( p <= 1 ) return false;
    if ( p == 2 ) return true;
    if ( p % 2 == 0 ) return false;
    for ( int i = 3; i * i <= p; i += 2 ) 
        if ( p % i == 0 )
            return false;
    return true;
}

int HashTable::getNextPrime(int n) const {
    unsigned int nextNum = n;
    while ( !isPrime(nextNum) ) nextNum++;
    return (int)nextNum;
}

HashTable::HashTable(int initialSize) : currentSize(0) {
    arraySize = getNextPrime(initialSize);
    table.resize(arraySize);
}

unsigned long HashTable::hash(const std::string& word) const {
    unsigned long hashVal = 5381; 
    for (char ch : word) {
        hashVal = ((hashVal << 5) + hashVal) + ch;
    }
    return hashVal % arraySize;
}

bool HashTable::insert(const std::string& word) {
    if (word.length() < 3) {
        return false;
    }
    
    if ((double)currentSize / arraySize > MAX_LOAD_FACTOR) {
        rehash();
    }

    unsigned long index = hash(word);

    for (const auto& existingWord : table[index]) {
        if (existingWord == word) {
            return false; 
        }
    }

    table[index].push_back(word);
    currentSize++;
    return true;
}

bool HashTable::contains(const std::string& word) const {
    if (word.length() < 3 || currentSize == 0) return false;

    unsigned long index = hash(word);

    for (const auto& existingWord : table[index]) {
        if (existingWord == word) {
            return true;
        }
    }

    return false;
}

void HashTable::rehash() {
    int oldArraySize = arraySize;
    int newArraySize = getNextPrime(oldArraySize * 2);

    std::vector<std::list<std::string>> newTable(newArraySize);
    std::vector<std::list<std::string>> oldTable = std::move(table);
    
    arraySize = newArraySize;
    table = std::move(newTable);
    currentSize = 0; 

    for (const auto& bucket : oldTable) {
        for (const auto& word : bucket) {
            unsigned long index = hash(word);
            table[index].push_back(word);
            currentSize++;
        }
    }
}
