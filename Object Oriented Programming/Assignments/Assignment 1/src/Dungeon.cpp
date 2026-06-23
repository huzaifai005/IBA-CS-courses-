#include "../header/Dungeon.hpp"
#include <iostream>

Dungeon::Dungeon(Player* p) : player(p), startRoom(nullptr) {}

Dungeon::~Dungeon() {
    Room* current = startRoom;
    while (current) {
        Room* next = current->getNextRoom();
        delete current;
        current = next;
    }
}

void Dungeon::addRoom(Room* newRoom) {
    if (!startRoom) startRoom = newRoom;
    else {
        Room* temp = startRoom;
        while (temp->getNextRoom()) temp = temp->getNextRoom();
        temp->setNextRoom(newRoom);
    }
}

void Dungeon::playGame() {
    Room* currentRoom = startRoom;
    while (currentRoom && player->getHealth() > 0 && player->getMovesLeft() > 0) {
        std::cout << "\nYou enter a new room: " << currentRoom->getDescription() << "\n";

        
        if (currentRoom->checkNPC()) {
            std::cout << "You encounter a mysterious old man!\n";
            std::cout << "The old man says: 'Answer my riddle, and you may pass.'\n";
            std::cout << "Riddle: I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?\n";
            std::string answer;
            std::cout << "Your answer: ";
            std::cin >> answer;
            if (answer == "echo" || answer == "Echo") {
                std::cout << "Correct! The old man allows you to pass.\n";
                currentRoom->solveRiddle();
            } else {
                std::cout << "Incorrect! You cannot proceed until you solve the riddle.\n";
                continue; 
            }
        }

        
        if (currentRoom->checkEnemy() || currentRoom->checkBoss()) {
            EnemyQueue& enemyQueue = currentRoom->getEnemyQueue();
            while (!enemyQueue.empty()) {
                Enemy* currentEnemy = enemyQueue.front();
                std::cout << "A wild " << currentEnemy->type << " appears!\n";
                while (currentEnemy->health > 0 && player->getHealth() > 0) {
                    std::cout << "Do you want to (a)ttack or (r)etreat? ";
                    char choice;
                    std::cin >> choice;
                    if (choice == 'a' || choice == 'A') {
                        player->attackEnemy(*currentEnemy);
                        if (currentEnemy->health > 0) {
                            int damage = currentEnemy->attackPower;
                            player->takeDamage(damage);
                            std::cout << "The " << currentEnemy->type << " attacks you and deals " << damage << " damage!\n";
                        }
                    } else if (choice == 'r' || choice == 'R') {
                        std::cout << "You retreat from the fight!\n";
                        break;
                    } else {
                        std::cout << "Invalid choice. Please enter 'a' to attack or 'r' to retreat.\n";
                    }
                }
                if (currentEnemy->health <= 0) {
                    std::cout << "You have defeated the " << currentEnemy->type << "!\n";
                    enemyQueue.dequeue();
                    player->increaseMove(2); 
                    std::cout << "You gained 2 extra moves!\n";
                    if (currentRoom->checkBoss()) {
                        currentRoom->defeatBoss();
                        std::cout << "You have defeated the final boss! The dungeon exit is now open.\n";
                    }
                }
            }
            if (enemyQueue.empty()) {
                if (currentRoom->checkEnemy()) {
                    currentRoom->defeatEnemy();
                }
            }
        }

        
        if (currentRoom->checkTreasure()) {
            std::cout << "You find some treasure: " << currentRoom->getTreasure()->name << " - " << currentRoom->getTreasure()->description << "\n";
            std::cout << "Do you want to pick it up? (y/n): ";
            char pickTreasure;
            std::cin >> pickTreasure;
            if (pickTreasure == 'y' || pickTreasure == 'Y') {
                currentRoom->collectTreasure();
                player->addToInventory(currentRoom->getTreasure()->name);
                player->useTreasure(currentRoom->getTreasure()->name);
                std::cout << "You collected the treasure!\n";
            }
        }

        
        if (currentRoom->checkWeapon()) {
            std::cout << "You find a weapon! Do you want to pick it up? (y/n): ";
            char pickWeapon;
            std::cin >> pickWeapon;
            if (pickWeapon == 'y' || pickWeapon == 'Y') {
                currentRoom->collectWeapon();
                player->collectWeapon();
                std::cout << "The weapon will help you in fights\n";
            }
        }

        
        if (currentRoom->isExitRoom() && currentRoom->isBossDefeated()) {
            std::cout << "\nCongratulations! you defeated the final boss\n";
            break;
        }

       
        std::cout << "Move to next room or backtrack? (n/b): ";
        std::string moveChoice;
        while (true) {
            std::cin >> moveChoice;
            if (moveChoice == "n" && currentRoom->getNextRoom()) {
                roomStack.push(currentRoom);
                currentRoom = currentRoom->getNextRoom();
                player->decreaseMove();
                break;
            } else if (moveChoice == "b") {
                Room* previousRoom = roomStack.pop();
                if (previousRoom) {
                    currentRoom = previousRoom;
                    player->decreaseMove();
                    break;
                } else {
                    std::cout << "You cannot backtrack further. You are at the starting room.\n";
                }
            } else {
                std::cout << "Invalid choice. Please enter 'n' to move to the next room or 'b' to backtrack: ";
            }
        }

        player->displayStatus();

        if (player->getMovesLeft() <= 0) {
            std::cout << "\nYou have run out of moves! Game over.\n";
            break;
        }
        if (player->getHealth() <= 0) {
            std::cout << "\nYou have been defeated! Game over.\n";
            break;
        }
    }


    if (player->getHealth() > 0 && player->getMovesLeft() > 0 && currentRoom && currentRoom->isExitRoom() && currentRoom->isBossDefeated()) {
        std::cout << "\nAt last, the exit comes into view, a beacon of hope in the distance. Without a moment's hesitation, you sprint toward it, your heart pounding with a mix of relief and exhilaration. Bursting out of the dungeon, you take in the fresh air, freedom finally yours. Yet, as you catch your breath, a lingering thought remains--the secrets of the dungeon are still shrouded in mystery, its enigma unsolved. The adventure may be over, but the story is far from complete.\n";
    }
}