#include "../header/EnemyQueue.hpp"

EnemyQueue::Node::Node(Enemy e) : enemy(e), next(nullptr) {}

EnemyQueue::EnemyQueue() : frontNode(nullptr), rearNode(nullptr) {}

EnemyQueue::~EnemyQueue() {
    while (!empty()) dequeue();
}

void EnemyQueue::enqueue(Enemy e) {
    Node* newNode = new Node(e);
    if (!rearNode) frontNode = rearNode = newNode;
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
}

void EnemyQueue::dequeue() {
    if (frontNode) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = nullptr;
        delete temp;
    }
}

Enemy* EnemyQueue::front() {
    return frontNode ? &frontNode->enemy : nullptr;
}

bool EnemyQueue::empty() {
    return frontNode == nullptr;
}