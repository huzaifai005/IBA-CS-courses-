#include<iostream>
struct node {
    int data;
    node* next;
};

int main() {
    node* first = new node();
    node* second = new node();
    node* third = new node();
    
    first->data = 5;
    second->data = 10;
    third-> data = 15;
    
    first->next = second;
    second->next = third;
    third->next = nullptr;
    
    std::cout << "Linked list values: " << std::endl;
    for (node* current = first; current != nullptr; current = current->next) {
        std::cout << current->data << " ";
    }
    
    
}
