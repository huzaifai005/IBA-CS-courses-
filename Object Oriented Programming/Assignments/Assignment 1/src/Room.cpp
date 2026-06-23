#include "../header/Room.hpp"
#include <cstdlib>
#include <ctime>

Room::Room(std::string desc, std::string chall, std::string rew, bool enemy, bool treasureFlag, bool weapon, bool npc, bool boss, bool exit)
    : description(desc), challenge(chall), reward(rew), hasEnemy(enemy), hasTreasure(treasureFlag), hasWeapon(weapon), hasNPC(npc), hasBoss(boss),
      enemyDefeated(false), treasureCollected(false), weaponCollected(false), riddleSolved(false), bossDefeated(false), nextRoom(nullptr), previousRoom(nullptr), treasure(nullptr), isExit(exit) {
    if (hasTreasure) {
        std::string treasureNames[] = {"Golden Chalice", "Ruby Amulet", "Diamond Crown", "Emerald Ring"};
        std::string treasureDescriptions[] = {"A golden chalice encrusted with jewels.", "A ruby amulet glowing with magical energy.", "A diamond crown fit for a king.", "An emerald ring said to bring good luck."};
        int index = rand() % 4;
        treasure = new Treasure(treasureNames[index], treasureDescriptions[index]);
    }
    if (hasEnemy) {
        int numEnemies = rand() % 3 + 1;
        for (int i = 0; i < numEnemies; i++) {
            enemyQueue.enqueue(Enemy());
        }
    }
    if (hasBoss) {
        Enemy bossEnemy;
        bossEnemy.type = "Dragon";
        bossEnemy.health = 100;
        bossEnemy.attackPower = 20;
        enemyQueue.enqueue(bossEnemy);
    }
}

Room::~Room() {
    delete treasure;
}

void Room::setNextRoom(Room* next) {
    nextRoom = next;
    if (next) next->previousRoom = this;
}

Room* Room::getNextRoom() const { return nextRoom; }
Room* Room::getPreviousRoom() const { return previousRoom; }
std::string Room::getDescription() const { return description; }

bool Room::checkEnemy() const { return hasEnemy && !enemyDefeated; }
bool Room::checkTreasure() const { return hasTreasure && !treasureCollected; }
bool Room::checkWeapon() const { return hasWeapon && !weaponCollected; }
bool Room::checkNPC() const { return hasNPC && !riddleSolved; }
bool Room::checkBoss() const { return hasBoss && !bossDefeated; }

void Room::defeatEnemy() { enemyDefeated = true; }
void Room::collectTreasure() { treasureCollected = true; }
void Room::collectWeapon() { weaponCollected = true; }
void Room::solveRiddle() { riddleSolved = true; }
void Room::defeatBoss() { bossDefeated = true; }

bool Room::isEnemyDefeated() const { return enemyDefeated; }
bool Room::isTreasureCollected() const { return treasureCollected; }
bool Room::isWeaponCollected() const { return weaponCollected; }
bool Room::isRiddleSolved() const { return riddleSolved; }
bool Room::isBossDefeated() const { return bossDefeated; }

Treasure* Room::getTreasure() const { return treasure; }
EnemyQueue& Room::getEnemyQueue() { return enemyQueue; }

bool Room::isExitRoom() const { return isExit; }