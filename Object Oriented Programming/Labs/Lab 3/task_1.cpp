

#include<iostream>

class DoublyLinkedList {
    private:
    struct Node {
        int data;
        Node* next;
        Node* previous;
    };

    Node* head;
    Node* tail;

    public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            head->previous = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {  
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->previous = temp;
            tail = newNode;
        }
    }

    void remNode(int value) {
        Node* temp1 = head;
        while (temp1 != nullptr && temp1->data != value) {  
            temp1 = temp1->next;
        }

        if (temp1 == nullptr) {
            std::cout << "No value found.\n";
            return;
        }

        if (temp1 == head) {
            head = temp1->next;
            if (head != nullptr) {
                head->previous = nullptr;
            }
        }
        else {
            temp1->previous->next = temp1->next;
        }

        if (temp1->next == nullptr) {
            tail = temp1->previous;
        }
        else {
            temp1->next->previous = temp1->previous;
        }

        delete temp1;
    }

    int getNode(int n) {
        Node* temp = head;
        for (int i = 0; i < n; i++) {
            if (temp != nullptr) {
                temp = temp->next;
            }
            else {
                std::cout << "No node found";
                return -1; 
            }
        }
        return temp ? temp->data : -1;
    }

    void traverseFor() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void traverseBack() {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->previous;
        }
    }
};

int main() {
    DoublyLinkedList a;
    a.addNode(10);
    a.addNode(20);
    a.addNode(30);
    a.addNode(40);
    a.addNode(50);

    a.traverseFor();
    std::cout << std::endl;
    a.traverseBack();
    std::cout << std::endl;
    a.remNode(10);
    a.remNode(30);
    a.traverseFor();
    std::cout << std::endl;
    a.traverseBack();
    std::cout << std::endl;
    std::cout << "Element at index 1: " << a.getNode(1) << std::endl;
}

