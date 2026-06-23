#include <vector>
#include <iostream>
#include <fstream>
#include "stopwatch.hpp"

int count(const std::vector<int>& a) {
    int n = a.size();

    int c = 0;
    for (int i = 0; i < n; i++)   
        for (int j = i+1; j < n; j++)
            for (int k = j+1; k < n; k++)
                if (a[i] + a[j] + a[k] == 0)
                    c++;

    return c;
}

int main() {
    std::vector<int> v1, v2, v3, v4, v5, v6;
    srand(static_cast<unsigned int>(time(nullptr)));

    for(int i = 0; i < 500; i++) {
        int random = rand() % 1000 + 1;
        v1.push_back(random);
    }
    Stopwatch stopwatch;
    count(v1);
    std::cout << "Time taken for n = 500: " << stopwatch.elapsedTime() << "seconds." << std::endl;

    for(int i = 0; i < 1000; i++) {
        int random = rand() % 1000 + 1;
        v2.push_back(random);
    }
    stopwatch.reset();
    count(v2);
    std::cout << "Time taken for n = 1000: " << stopwatch.elapsedTime() << "seconds." << std::endl;

    for(int i = 0; i < 2000; i++) {
        int random = rand() % 1000 + 1;
        v3.push_back(random);
    }
    stopwatch.reset();
    count(v3);
    std::cout << "Time taken for n = 2000: " << stopwatch.elapsedTime() << "seconds." << std::endl;

    for(int i = 0; i < 4000; i++) {
        int random = rand() % 1000 + 1;
        v4.push_back(random);
    }
    stopwatch.reset();
    count(v4);
    std::cout << "Time taken for n = 4000: " << stopwatch.elapsedTime() << "seconds." << std::endl;

    for(int i = 0; i < 8000; i++) {
        int random = rand() % 1000 + 1;
        v5.push_back(random);
    }
    stopwatch.reset();
    count(v5);
    std::cout << "Time taken for n = 8000: " << stopwatch.elapsedTime() << "seconds." << std::endl;

    for(int i = 0; i < 16000; i++) {
        int random = rand() % 1000 + 1;
        v6.push_back(random);
    }
    stopwatch.reset();
    count(v6);
    std::cout << "Time taken for n = 16000: " << stopwatch.elapsedTime() << "seconds." << std::endl;
}



