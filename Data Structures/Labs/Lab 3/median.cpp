#include<iostream>
#include <stdexcept>
#include <cstdlib>
#include<utility>
using namespace std;

template<typename Key> 
class dynamicMedian {
    private:

    class maxHeap {
        private: 
            int capacity;
            int n;
            Key* pq;

        public: 
            maxHeap() : capacity{2}, n{0}    {  
                pq = new Key[capacity+1];  
            }
            
            ~maxHeap() {  
                delete[] pq;  
            }

            bool empty() const {   
                return n == 0;   
            }

            int  size() const {   
                return n;        
            }

            void insert(Key x) {            
                if(n == capacity) 
                    resize(2 * capacity);
                pq[++n] = x;
                swim(n);
            }

            Key delMax() {
                if(n==0) 
                    throw std::runtime_error("Priority queue underflow");
                if(n == capacity / 4 && capacity > 2) 
                    resize(capacity / 2);
                std::swap(pq[1], pq[n--]);
                sink(1);
                return std::move(pq[n+1]);
            }

        private:   
            void resize(int newCapacity) {
                Key* newPq = new Key[newCapacity + 1];
                for(int i = 1; i <= n; i++) {
                    newPq[i] = std::move(pq[i]);
                }
                delete[] pq;
                pq = newPq;
                capacity = newCapacity;
            }
            
            void swim(int k) {
                while (k > 1 && pq[k/2] < pq[k]) {
                    std::swap(pq[k], pq[k/2]);
                    k = k/2;
                }
            }

            void sink(int k) {
                while (2*k <= n) {
                    int j = 2*k;
                    if (j < n && pq[j] < pq[j+1])
                        j++;
                    if (!(pq[k] < pq[j])) break;
                    std::swap(pq[k], pq[j]);
                    k = j;
                }
            }
    };

    class minHeap {
        private: 
            int capacity;
            int n;
            Key* pq;

        public: 
            minHeap() : capacity{2}, n{0}    {  
                pq = new Key[capacity+1];  
            }
            
            ~minHeap() {  
                delete[] pq;  
            }

            bool empty() const {   
                return n == 0;   
            }

            int  size() const {   
                return n;        
            }

            void insert(Key x) {            
                if(n == capacity) 
                    resize(2 * capacity);
                pq[++n] = x;
                swim(n);
            }

            Key delMin() {
                if(n==0) 
                    throw std::runtime_error("Priority queue underflow");
                if(n == capacity / 4 && capacity > 2) 
                    resize(capacity / 2);
                std::swap(pq[1], pq[n--]);
                sink(1);
                return std::move(pq[n+1]);
            }

        private:   
            void resize(int newCapacity) {
                Key* newPq = new Key[newCapacity + 1];
                for(int i = 1; i <= n; i++) {
                    newPq[i] = std::move(pq[i]);
                }
                delete[] pq;
                pq = newPq;
                capacity = newCapacity;
            }
            
            void swim(int k) {
                while (k > 1 && pq[k/2] > pq[k]) {
                    std::swap(pq[k], pq[k/2]);
                    k = k/2;
                }
            }

            void sink(int k) {
                while (2*k <= n) {
                    int j = 2*k;
                    if (j < n && pq[j] > pq[j+1])
                        j++;
                    if (!(pq[k] > pq[j])) break;
                    std::swap(pq[k], pq[j]);
                    k = j;
                }
            }
    };
    
    Key v;
    bool hasMedian;  // NEW FLAG
    maxHeap left;
    minHeap right;
    
    public:
    dynamicMedian() : hasMedian(false) {};

    ~dynamicMedian() {};

    void insert(Key x) {
        if(!hasMedian) {
            v = x;
            hasMedian = true;
            return;
        }

        if(x <= v) {
            left.insert(x);
        }
        else {
            right.insert(x);
        }

        if(left.size() > right.size() + 1) {
            right.insert(v);
            v = left.delMax();
        }
        else if(right.size() > left.size() + 1) {
            left.insert(v);
            v = right.delMin();
        }
    }

    Key median() const {
        if (!hasMedian) {
            throw std::runtime_error("No elements");
        }
        return v;
    }

    Key removeMedian() {
        if (!hasMedian) {
            throw std::runtime_error("No elements");
        }
        
        Key oldMedian = v;

        if (left.empty() && right.empty()) {
            hasMedian = false; // completely empty now
        }
        else if (left.size() >= right.size()) {
            v = left.delMax();
        } 
        else {
            v = right.delMin();
        }
        
        return oldMedian;
    }

};


int main() {
    dynamicMedian<int> dm;

    int arr[] = {10, 20, 30, 40, 50};
    for (int x : arr) {
        dm.insert(x);
        cout << "Inserted: " << x 
             << ", Current Median: " << dm.median() << endl;
    }

    while (true) {
        try {
            cout << "Removed Median: " << dm.removeMedian() << endl;
            cout << "New Median: " << dm.median() << endl;
        } catch (const runtime_error& e) {
            cout << "No more elements to remove." << endl;
            break;
        }
    }

    return 0;
}
