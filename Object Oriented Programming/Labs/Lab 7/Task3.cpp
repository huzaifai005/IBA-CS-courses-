#include<queue>
#include<iostream>
#include "memorytracker.hpp"
#include<cstdlib>
#include<ctime>

class Packet {
protected:
int* valueArray;

public:
Packet() : valueArray(new int[10]) {}

virtual ~Packet() {
    delete[] valueArray;
}
};

class TCPSegment : public Packet {
protected:
int* TCPArray;

public:
TCPSegment() : TCPArray(new int[10]) {}

~TCPSegment() {
    delete[] TCPArray;
}
};

class UDPSegment : public Packet {
private:
int* UDPArray;

public:
UDPSegment() : UDPArray(new int[10]) {}

~UDPSegment() {
    delete[] UDPArray;
}
};

int main() {
    srand(time(0));
    {
    std::queue<Packet*> p;
    for (int i = 0; i < 10; i++) {
        if(rand()%2 == 0) {
            p.push(new UDPSegment);
        }
        else {
            p.push(new TCPSegment);
        }
    }

    Packet* temp;
    while(!p.empty()) {
        temp = p.front();
        delete temp;
        p.pop();

    }
    }

    MemoryTracker::report();
}
