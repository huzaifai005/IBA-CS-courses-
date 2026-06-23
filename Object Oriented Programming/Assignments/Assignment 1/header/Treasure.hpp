#ifndef TREASURE_H
#define TREASURE_H

#include <string>

class Treasure {
public:
    std::string name;
    std::string description;

    Treasure(std::string n, std::string desc);
};

#endif