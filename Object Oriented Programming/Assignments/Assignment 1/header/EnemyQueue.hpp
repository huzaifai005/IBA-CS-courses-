#ifndef ENEMYQUEUE_H
#define ENEMYQUEUE_H

#include "Enemy.hpp"

class EnemyQueue {
private:
    struct Node {
        Enemy enemy;
        Node* next;
        Node(Enemy e);
    };
    Node* frontNode, *rearNode;
public:
    EnemyQueue();
    ~EnemyQueue();
    void enqueue(Enemy e);
    void dequeue();
    Enemy* front();
    bool empty();
};

#endif