#include "../header/RoomStack.hpp"

RoomStack::StackNode::StackNode(Room* r) : room(r), next(nullptr) {}

RoomStack::RoomStack() : top(nullptr) {}

RoomStack::~RoomStack() {
    while (!isEmpty()) pop();
}

void RoomStack::push(Room* room) {
    StackNode* newNode = new StackNode(room);
    newNode->next = top;
    top = newNode;
}

Room* RoomStack::pop() {
    if (isEmpty()) return nullptr;
    StackNode* temp = top;
    Room* room = temp->room;
    top = top->next;
    delete temp;
    return room;
}

bool RoomStack::isEmpty() {
    return top == nullptr;
}