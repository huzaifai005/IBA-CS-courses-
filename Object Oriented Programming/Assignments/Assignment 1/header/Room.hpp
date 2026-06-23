#ifndef ROOM_H
#define ROOM_H

#include "EnemyQueue.hpp"
#include "Treasure.hpp"

class Room {
private:
    std::string description;
    std::string challenge;
    std::string reward;
    bool hasEnemy;
    bool hasTreasure;
    bool hasWeapon;
    bool hasNPC; 
    bool hasBoss;
    bool enemyDefeated;
    bool treasureCollected;
    bool weaponCollected;
    bool riddleSolved;
    bool bossDefeated;                  
    Room* nextRoom;
    Room* previousRoom;
    Treasure* treasure;
    EnemyQueue enemyQueue;
    bool isExit;

public:
    Room(std::string desc, std::string chall, std::string rew, bool enemy, bool treasureFlag, bool weapon, bool npc = false, bool boss = false, bool exit = false);
    ~Room();

    void setNextRoom(Room* next);
    Room* getNextRoom() const;
    Room* getPreviousRoom() const;
    std::string getDescription() const;

    bool checkEnemy() const;
    bool checkTreasure() const;
    bool checkWeapon() const;
    bool checkNPC() const;
    bool checkBoss() const;

    void defeatEnemy();
    void collectTreasure();
    void collectWeapon();
    void solveRiddle();
    void defeatBoss();

    bool isEnemyDefeated() const;
    bool isTreasureCollected() const;
    bool isWeaponCollected() const;
    bool isRiddleSolved() const;
    bool isBossDefeated() const;

    Treasure* getTreasure() const;
    EnemyQueue& getEnemyQueue();

    bool isExitRoom() const;
};

#endif