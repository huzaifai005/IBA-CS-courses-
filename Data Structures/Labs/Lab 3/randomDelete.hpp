#pragma once

#include <stdexcept>
#include <cstdlib>
#include<utility>

template<typename Key> 
class MaxPQ {
    private: 
        int capacity;
        int n;
        Key* pq;

    public: 
        MaxPQ() : capacity{2}, n{0}    {  
            pq = new Key[capacity+1];  
        }
        
        ~MaxPQ() {  
            delete[] pq;  
        }

        bool empty() {   
            return n == 0;   
        }

        int  size()  {   
            return n;        
        }

        void insert(Key x) {
            // Add overflow check and resizing logic
            if(n == capacity) 
               resize(2 * capacity);

            // Insert new element at the end of the heap
            // and then swim it to restore heap order
            pq[++n] = x;
            swim(n);
        }

        Key delMax() {
            // Add underflow check and resizing logic
            if(n==0) 
               throw std::runtime_error("Priority queue underflow");
            else if(n == capacity / 4) 
               resize(capacity / 2);

            // Exchange the root of the heap with the last element
            // and then sink the new root to restore heap order
            std::swap(pq[1], pq[n--]);
            sink(1);
            return std::move(pq[n+1]);
        }
        
        Key deleteRandom() {
            if(n==0) {
                throw std::runtime_error("Priority queue underflow");
            } 
            
            int randIndex = rand() % n + 1;
            
            std::swap(pq[randIndex], pq[n--]);
            
            if (randIndex <= n) {
                swim(randIndex);
                sink(randIndex);
            }
            
            if (n == capacity / 4) {
                resize(capacity / 2);
            }
            
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
