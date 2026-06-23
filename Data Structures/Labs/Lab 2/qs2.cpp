#include<iostream>

class EggDrop {
private:
int m;

public:
EggDrop(int n) : m(rand() % n + 1) {}

bool operator()(int x) {
if (x >= m) {
return true;
};
return false;
}

};

int main() {
srand(static_cast<unsigned int>(time(nullptr)));
int n = 10000;
EggDrop eggdrop(n);

int lo = 1;
int hi = 1;
while (hi < n && !eggdrop(hi)) {
    lo = hi;
    hi *= 2;
}
if (hi > n) {
    hi = n;
}

while (lo < hi) {
int mid = lo + (hi-lo)/2;
if (eggdrop(mid)) hi = mid;
else lo = mid+1;
}

std::cout << "The value of m is " << lo << std::endl;
return 0;
}
