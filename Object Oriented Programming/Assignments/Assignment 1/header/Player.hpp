#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int health, movesLeft, attackPower;
    bool hasWeapon;
    std::string* inventory;
    int inventorySize;
    int inventoryCapacity;

    void resizeInventory();

public:
    Player(std::string playerName, int hp, int moves);
    ~Player();

    void takeDamage(int damage);
    void attackEnemy(class Enemy& enemy);

    int getHealth() const;
    int getMovesLeft() const;
    void decreaseMove();
    void increaseMove(int extraMoves);
    void displayStatus() const;

    void collectWeapon();
    void addToInventory(const std::string& item);
    void useTreasure(const std::string& treasureName);

    bool hasCollectedWeapon() const;
    void displayInventory() const;
};

#endif