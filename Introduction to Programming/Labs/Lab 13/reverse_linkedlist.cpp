#include <iostream>
using std::cout;

struct node {
    int data;      
    node* next;    
};

node* reverseList(node* head) {
    node* reverse = nullptr;
    node* first = head;
    while (first!=nullptr) {
        node* second = first->next;
        first->next = reverse;
        reverse = first;
        first = second;
    }
    return reverse;
}

int main() {
    node* first = new node(); 
    node* second = new node(); 
    node* third = new node(); 

    first->data = 5;
    second->data = 10;
    third->data = 15;

    first->next = second; 
    second->next = third; 
    third->next = nullptr;

    first = reverseList(first);
    std::cout << "Linked list values:" << std::endl;
    for (node* current = first; current != nullptr; current = current->next) {
        std::cout << current->data << " "; 
    }
}