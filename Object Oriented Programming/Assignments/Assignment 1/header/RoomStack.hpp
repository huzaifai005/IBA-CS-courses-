#ifndef ROOMSTACK_H
#define ROOMSTACK_H

#include "Room.hpp"

class RoomStack {
private:
    struct StackNode {
        Room* room;
        StackNode* next;
        StackNode(Room* r);
    };
    StackNode* top;
public:
    RoomStack();
    ~RoomStack();
    void push(Room* room);
    Room* pop();
    bool isEmpty();
};

#endif