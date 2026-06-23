#include<iostream>

template <typename T>
class Stack {
private:

struct node{
T data;
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
void push(T x) {
    node* newnode = new node();
    newnode->data = x;
        newnode->next=head;
        head=newnode;
        s++;
    
}

T pop() {
    if(isEmpty()) {
        throw std::out_of_range("Stack is Empty");
    }
    else{
        node* val = head;
        T a = head->data;
        head = head->next;
        delete val;
        s--;
        return a;
    }
}

T top() {
    if(isEmpty()) {
        throw std::out_of_range("Stack is Empty");
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
    Stack<int> s1;
    
    s1.push(1);
    s1.push(2);
    s1.push(3);
    std::cout << "Int Stack: " <<  s1.pop() << " " << s1.pop() << " " << s1.pop() << std::endl;

    Stack<double> s2;
    s2.push(1.1);
    s2.push(2.1);
    s2.push(3.1);
    std::cout << "Double Stack: " <<  s2.pop() << " " << s2.pop() << " " << s2.pop() <<std::endl;

    Stack<std::string> s3;
    s3.push("hello ");
    s3.push("world");
    std::cout << "String Stack: " <<  s3.pop() << " " << s3.pop();
}