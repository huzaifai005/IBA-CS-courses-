#ifndef DUNGEON_H
#define DUNGEON_H

#include "Player.hpp"
#include "Room.hpp"
#include "RoomStack.hpp"

class Dungeon {
private:
    Player* player;
    Room* startRoom;
    RoomStack roomStack;
public:
    Dungeon(Player* p);
    ~Dungeon();

    void addRoom(Room* newRoom);
    void playGame();
};

#endif