#include "../header/Enemy.hpp"
#include <cstdlib>
#include <ctime>

Enemy::Enemy() {
    std::string enemyTypes[] = {"Goblin", "Skeleton", "Orc", "Dark Mage"};
    type = enemyTypes[rand() % 4];
    if (type == "Goblin") {
        attackPower = rand() % 5 + 5;
        health = rand() % 10 + 10;
    } else if (type == "Skeleton") {
        attackPower = rand() % 7 + 7;
        health = rand() % 15 + 15;
    } else if (type == "Orc") {
        attackPower = rand() % 10 + 10;
        health = rand() % 20 + 20;
    } else if (type == "Dark Mage") {
        attackPower = rand() % 12 + 12;
        health = rand() % 25 + 25;
    }
}