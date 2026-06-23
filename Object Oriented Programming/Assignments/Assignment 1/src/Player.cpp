#include "../header/Player.hpp"
#include "../header/Enemy.hpp"
#include <iostream>

Player::Player(std::string playerName, int hp, int moves)
    : name(playerName), health(hp), movesLeft(moves), attackPower(10), hasWeapon(false), inventorySize(0), inventoryCapacity(5) {
    inventory = new std::string[inventoryCapacity];
}

Player::~Player() {
    delete[] inventory;
}

void Player::takeDamage(int damage) { health -= damage; }

void Player::attackEnemy(Enemy& enemy) {
    int damage = rand() % 10 + attackPower;
    enemy.health -= damage;
    std::cout << "You attack the " << enemy.type << " and deal " << damage << " damage!\n";
}

int Player::getHealth() const { return health; }
int Player::getMovesLeft() const { return movesLeft; }
void Player::decreaseMove() { movesLeft--; }
void Player::increaseMove(int extraMoves) { movesLeft += extraMoves; }

void Player::displayStatus() const {
    std::cout << "\nPlayer: " << name << " | Health: " << health << " | Moves left: " << movesLeft;
    std::cout << " | Weapon: " << (hasWeapon ? "Yes" : "No") << " | Attack Power: " << attackPower << "\n";
    std::cout << "Inventory: ";
    for (int i = 0; i < inventorySize; i++) {
        std::cout << inventory[i] << (i < inventorySize - 1 ? ", " : "\n");
    }
}

void Player::collectWeapon() {
    hasWeapon = true;
    attackPower += 5;
    addToInventory("Weapon");
    std::cout << "You collected a weapon! Your attack power is now " << attackPower << "!\n";
}

void Player::addToInventory(const std::string& item) {
    if (inventorySize >= inventoryCapacity) {
        resizeInventory();
    }
    inventory[inventorySize++] = item;
}

void Player::useTreasure(const std::string& treasureName) {
    if (treasureName == "Golden Chalice") {
        health += 20;
        std::cout << "You drink from the Golden Chalice and restore 20 health!\n";
    } else if (treasureName == "Ruby Amulet") {
        attackPower += 5;
        std::cout << "You equip the Ruby Amulet and gain 5 attack power!\n";
    } else if (treasureName == "Diamond Crown") {
        health += 10;
        attackPower += 3;
        std::cout << "You wear the Diamond Crown and restore 10 health and gain 3 attack power!\n";
    } else if (treasureName == "Emerald Ring") {
        health += 15;
        std::cout << "You wear the Emerald Ring and restore 15 health!\n";
    }
}

bool Player::hasCollectedWeapon() const { return hasWeapon; }

void Player::displayInventory() const {
    std::cout << "\nInventory: ";
    for (int i = 0; i < inventorySize; i++) {
        std::cout << inventory[i] << (i < inventorySize - 1 ? ", " : "\n");
    }
}

void Player::resizeInventory() {
    inventoryCapacity *= 2;
    std::string* newInventory = new std::string[inventoryCapacity];
    for (int i = 0; i < inventorySize; i++) {
        newInventory[i] = inventory[i];
    }
    delete[] inventory;
    inventory = newInventory;
}