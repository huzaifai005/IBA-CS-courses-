#include<iostream>

//The reason I have used linked list implementaton is because it has better time complexity than dynamic array. Linked list have a time complexity of O(1) whereas dynamic array have time complexity if O(n) in the worst case. In the worst case of the dynamic array we run out of the capacity that our array has and we will then have to resize our array. In linked list however we don't have to resize since we do not have a fixed capacity and we make our nodes as needed.

class Stack {
private:

struct node{
int data;
node* next;
};

node* head;
int s;

public:
Stack() : head(nullptr), s(0) {}

bool isEmpty() {
    if(head==nullptr) {
        return true;
    }
    else {
        return false;
    }
}
void push(int x) {
    node* newnode = new node();
    newnode->data = x;
        newnode->next=head;
        head=newnode;
        s++;
    
}

int pop() {
    if(isEmpty()) {
        std::cout << "The stack is empty." << std::endl;
        return 0;
    }
    else{
        node* val = head;
        int a = head->data;
        head = head->next;
        delete val;
        s--;
        return a;
    }
}

int top() {
    if(isEmpty()) {
        std::cout << "The stack is empty." << std::endl;
        return 0;
    }
    else {
        return head->data;
    }
}

int size() {
    return s;
}

~Stack() {
    while(head!=nullptr) {
        node* temp = head;
        head=head->next;
        delete temp;
    }
}



};

int main() {
    Stack s1;

    s1.push(10);
    s1.push(20);

    std::cout << "The value at the top is: " << s1.top() << std::endl;
    
    std::cout << "The size of the stack is: " << s1.size() << std::endl;
    
    std::cout << "The value being removed is: " << s1.pop() << std::endl;
    
    std::cout << "The size of the stack is: " << s1.size() << std::endl;
    
    std::cout << "The value at the top is: " << s1.top() << std::endl;

}