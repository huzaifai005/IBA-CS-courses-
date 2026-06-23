#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    std::string type;
    int attackPower, health;
    Enemy();
};

#endif