#include <stdexcept>
#include <cstdlib>
#include <utility>
#include <iostream>
using namespace std;

template<typename Key> 
class MinPQ {
private:
    int capacity;
    int n;
    Key* pq;

public: 
    MinPQ() : capacity{2}, n{0} {  
        pq = new Key[capacity+1];  
    }
    
    ~MinPQ() {  
        delete[] pq;  
    }

    bool empty() {   
        return n == 0;   
    }

    int size() {   
        return n;        
    }

    void insert(Key x) {
        if (n == capacity) 
            resize(2 * capacity);
        pq[++n] = x;
        swim(n);
    }

    Key delMin() {
        if (n == 0) 
            throw std::runtime_error("Priority queue underflow");
        else if (n == capacity / 4) 
            resize(capacity / 2);

        std::swap(pq[1], pq[n--]);
        sink(1);
        return std::move(pq[n+1]);
    }

private:   
    void resize(int newCapacity) {
        Key* newPq = new Key[newCapacity + 1];
        for (int i = 1; i <= n; i++) {
            newPq[i] = std::move(pq[i]);
        }
        delete[] pq;
        pq = newPq;
        capacity = newCapacity;
    }
    
    void swim(int k) {
        while (k > 1 && pq[k] < pq[k/2]) {  
            std::swap(pq[k], pq[k/2]);
            k = k/2;
        }
    }

    void sink(int k) {
        while (2*k <= n) {
            int j = 2*k;
            if (j < n && pq[j+1] < pq[j]) 
                j++;
            if (!(pq[j] < pq[k])) break;
            std::swap(pq[k], pq[j]);
            k = j;
        }
    }
};

struct CubeSum {
    long long value;
    int i, j;

    CubeSum(long long v=0, int a=0, int b=0) : value(v), i(a), j(b) {}

    bool operator<(const CubeSum& other) const {
        return value < other.value;
    }
    bool operator>(const CubeSum& other) const {
        return value > other.value;
    }
};

void printAllSums(int n) {
    MinPQ<CubeSum> pq;

    for (int i = 0; i <= n; i++) {
        pq.insert(CubeSum(1LL * i * i * i + 1LL * i * i * i, i, i));
    }

    cout << "All sums a^3 + b^3 for 0 <= a, b <= " << n << " in sorted order:\n";
    while (!pq.empty()) {
        CubeSum cs = pq.delMin();
        cout << cs.value << " = " << cs.i << "^3 + " << cs.j << "^3\n";

        if (cs.j < n) {
            int newJ = cs.j + 1;
            pq.insert(CubeSum(1LL * cs.i * cs.i * cs.i + 1LL * newJ * newJ * newJ, cs.i, newJ));
        }
    }
}

void findTaxicabNumbers(int n) {
    MinPQ<CubeSum> pq;

    for (int i = 0; i <= n; i++) {
        pq.insert(CubeSum(1LL * i * i * i + 1LL * i * i * i, i, i));
    }

    CubeSum prev(0, -1, -1);
    bool first = true;

    cout << "\nTaxicab numbers (distinct pairs with same sum):\n";
    while (!pq.empty()) {
        CubeSum cs = pq.delMin();

        if (!first && cs.value == prev.value) {
            cout << cs.value << " = "
                 << prev.i << "^3 + " << prev.j << "^3"
                 << " = " << cs.i << "^3 + " << cs.j << "^3\n";
        }
        first = false;
        prev = cs;

        if (cs.j < n) {
            int newJ = cs.j + 1;
            pq.insert(CubeSum(1LL * cs.i * cs.i * cs.i + 1LL * newJ * newJ * newJ, cs.i, newJ));
        }
    }
}

int main() {
    int n = 20;
    printAllSums(n);
    findTaxicabNumbers(n);
    return 0;
}

