#include<iostream>
struct node {
    int data;
    node* next;
};

void print(node* first) {
    if(first == nullptr) {
        return;
    }
    std::cout << first->data << " ";
    print(first->next);
}

void rprint(node* first) {
    if(first == nullptr) {
        return;
    }
    rprint(first->next);
    std::cout << first->data << " ";
}

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
    
    std::cout << "Forward order: ";
    print(first);
    
    std::cout << std::endl << "Reverse order: ";
    rprint(first);
    }
    
    

