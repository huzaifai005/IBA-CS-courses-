#include <iostream>

//The reason I have used linked list implementaton is because it has better time complexity than dynamic array. Linked list have a time complexity of O(1) whereas dynamic array have time complexity if O(n) in the worst case. In the worst case of the dynamic array we run out of the capacity that our array has and we will then have to resize our array. In linked list however we don't have to resize since we do not have a fixed capacity and we make our nodes as needed

class Queue {
private:

    struct node {
        int data;
        node* next;
    };

    node* front;
    node* rear;
    int s;

public:
    Queue() : front(nullptr), rear(nullptr), s(0) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int x) {
        node* newNode = new node();
        newNode->data = x;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;  
        } else {
            rear->next = newNode;  
            rear = newNode;  
        }

        s++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "The queue is empty." << std::endl;
            return 0;
        } else {
            node* val = front;
            int a = front->data;
            front = front->next;  
            if (front == nullptr) {  
                rear = nullptr;
            }
            delete val;
            s--;
            return a;
        }
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "The queue is empty." << std::endl;
            return 0;
        } else {
            return front->data;
        }
    }

    int size() {
        return s;
    }

    ~Queue() {
        while (front != nullptr) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    Queue q1;

    q1.enqueue(10);
    q1.enqueue(20);

    std::cout << "The value at the front is: " << q1.getFront() << std::endl;
    
    std::cout << "The size of the queue is: " << q1.size() << std::endl;
    
    std::cout << "The value being removed is: " << q1.dequeue() << std::endl;
    
    std::cout << "The size of the queue is: " << q1.size() << std::endl;
    
    std::cout << "The value at the front is: " << q1.getFront() << std::endl;

    return 0;
}
