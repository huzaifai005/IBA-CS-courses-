#include <iostream>
using std::cout;

struct Node {
    int data;      
    Node* next;    
};

void insertEnd(Node*& first, int value) {
    Node* newNode = new Node{value, nullptr}; 

    Node* current = first;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    Node* first = new Node(); 
    Node* second = new Node(); 
    Node* third = new Node(); 

    first->data = 5;
    second->data = 10;
    third->data = 15;

    first->next = second; 
    second->next = third; 
    third->next = nullptr;

    insertEnd(first, 20);
    cout << "Linked list values:" << "\n";
    for (Node* current = first; current != nullptr; current = current->next) {
        cout << current->data << " "; 
    }
    return 0;
}