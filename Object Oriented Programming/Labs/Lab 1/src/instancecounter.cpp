#include "../headers/instanceCounter.hpp"

int instanceCounter::count = 0;

instanceCounter::instanceCounter() {
count++;
}

int instanceCounter::getCount() {
    return count;
}