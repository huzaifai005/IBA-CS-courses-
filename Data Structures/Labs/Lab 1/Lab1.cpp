#include <iostream>
#include <string>
#include "StopWatch.hpp"
using std::string, std::cout;

// =============================
// Part A: Resizable Array
// =============================
class ResizableArray {
private:
    int* data;
    int capacity;
    int size;

    void resize(int newCapacity) {
        int* newdata = new int[newCapacity]; 
        for(int i = 0; i < size; i++) {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        capacity = newCapacity;
    }

public:
    ResizableArray() : capacity(2), size(0) {
        data = new int[capacity];
    }

    ResizableArray(const ResizableArray& other) : capacity(other.capacity), size(other.size) {
        data = new int[capacity];
        for(int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~ResizableArray() {
        delete[] data;
    }

    void push_back(int value) {
        if(size >= capacity) {
            resize(capacity*2);
        }
        data[size] = value;
        size++;
    }

    void pop_back() {
        if(empty()) {
            throw std::runtime_error("Cannot pop from empty array");
        }
        else {
            size--;
            if (size == capacity/4) {
                resize(capacity/2);
            }
        }
    }

    int get(int index) const {
        if(index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        else {
            return data[index];
        }
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size==0;
        }
    };

// =============================
// Part B: Linked List
// =============================


class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current != nullptr) {
            insertAtTail(current->data);
            current = current->next;
        }
    }
    
    ~LinkedList() {
        Node* temp = head;
        while(temp != nullptr) {
            head = head->next;
            delete temp;
            temp = head;   
        }
    }

    void insertAtHead(int value) {
        Node* newnode = new Node(value);
        newnode->next = head;
        head = newnode;
        if(tail == nullptr) {  
            tail = newnode;
        }
        size++;
    }

    void insertAtTail(int value) {
        Node* newnode = new Node(value);
        if(empty()) {
            head = tail = newnode;
        }
        else {
        tail->next = newnode;
        tail = newnode;
        }
        size++;
    }

    void deleteHead() {
        if(empty()) {
            throw std::runtime_error("Cannot delete from empty list");
        }
        Node* temp = head;
        head = head->next;
        if(head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        size--;   
    }

    int get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

    bool empty() const {
        return size==0;
    }

    int getSize() const {
            return size;
    }
};

// =============================
// Part C: Stack Implementations
// =============================

// --- Stack using ResizableArray ---
class ArrayStack {
private:
    ResizableArray arr;

public:

    ArrayStack() = default;
    ArrayStack(const ArrayStack& other) : arr(other.arr) {}

    void push(int value) {
        arr.push_back(value);
    }

    void pop() {
        arr.pop_back();
    }

    int top() const {
        return arr.get(arr.getSize() - 1);
    }

    bool empty() const {
        return arr.empty();
    }
};

// --- Stack using LinkedList ---
class LinkedListStack {
private:
    LinkedList list;

public:
    LinkedListStack() = default;
    LinkedListStack(const LinkedListStack& other) : list(other.list) {}

    void push(int value) {
        list.insertAtHead(value);
    }

    void pop() {
        list.deleteHead();
    }

    int top() const {
        return list.get(0);
    }

    bool empty() const {
       return list.empty();
    }
};

// =============================
// Part D: Text Buffer
// =============================

// --- TextBuffer using ArrayStack ---
class TextBufferArray {
private:
    ArrayStack left;   // characters to the left of cursor
    ArrayStack right;  // characters to the right of cursor

public:
    void insert(char c) {
        left.push(c);
    }

    void remove() {
        left.pop();
    }

    void moveLeft() {
        int charC = left.top(); 
        left.pop();
        right.push(charC);
    }

    void moveRight() {
        int charC = right.top();
        right.pop();
        left.push(charC);
    }

    string getText() {
        ArrayStack Temp;
        ArrayStack left2 = left;
        ArrayStack right2 = right;
        while(!left2.empty()) {
            Temp.push(left2.top());
            left2.pop();
        }
        string final;
        while(!Temp.empty()) {
            final = final + static_cast<char>(Temp.top());;
            Temp.pop();
        }
        while(!right2.empty()) {
            final = final + static_cast<char>(right2.top());;
            right2.pop();
        }
        return final;
    }
};

// --- TextBuffer using LinkedListStack ---
class TextBufferList {
private:
    LinkedListStack left;
    LinkedListStack right;

public:
    void insert(char c) {
        left.push(c);
    }

    void remove() {
        left.pop();
    }

    void moveLeft() {
        int charC = left.top();
        left.pop();
        right.push(charC);
    }

    void moveRight() {
        int charC = right.top();
        right.pop();
        left.push(charC);
    }

    string getText() {
        LinkedListStack Temp;
        LinkedListStack left2 = left;
        LinkedListStack right2 = right;
        while(!left2.empty()) {
            Temp.push(left2.top());
            left2.pop();
        }
        string final;
        while(!Temp.empty()) {
            final = final + static_cast<char>(Temp.top());;
            Temp.pop();
        }
        while(!right2.empty()) {
            final = final + static_cast<char>(right2.top());;
            right2.pop();
        }
        return final;
    }
};

// =============================
// Driver Program
// =============================
int main() {
    cout << "Testing TextBuffer with ArrayStack...\n";
    TextBufferArray buf1;
    string text = "datastructures";

    Stopwatch watch;
    for (char c : text) buf1.insert(c);

    buf1.moveLeft(); buf1.moveLeft(); buf1.moveLeft(); buf1.moveLeft(); buf1.moveLeft();
    buf1.insert('X');
    cout << "After inserting X: " << buf1.getText() << std::endl;

    buf1.remove();
    buf1.remove();
    buf1.remove();
    cout << "After deleting 3 chars: " << buf1.getText() << std::endl;

    buf1.moveRight();
    buf1.moveRight();
    buf1.insert('Y');
    cout << "After inserting Y: " << buf1.getText() << std::endl;
    std::cout << "Time taken to perform one iteration of all operations on array stack is: " << watch.elapsedTime() << " seconds" << std::endl;
    std::cout << std::endl;


    cout << "\nTesting TextBuffer with LinkedListStack...\n";
    TextBufferList buf2;
    watch.reset();
    for (char c : text) buf2.insert(c);

    buf2.moveLeft(); buf2.moveLeft(); buf2.moveLeft(); buf2.moveLeft(); buf2.moveLeft();
    buf2.insert('X');
    cout << "After inserting X: " << buf2.getText() << std::endl;

    buf2.remove();
    buf2.remove();
    buf2.remove();
    cout << "After deleting 3 chars: " << buf2.getText() << std::endl;

    buf2.moveRight();
    buf2.moveRight();
    buf2.insert('Y');
    cout << "After inserting Y: " << buf2.getText() <<std::endl;
    std::cout << "Time taken to perform one iteration of all operations on linked list stack is: " << watch.elapsedTime() << " seconds" << std::endl;
    std::cout <<std::endl;

    double arrayStackTotal = 0;
    double linkedListStackTotal = 0;

    
    for(int i = 0; i < 1000; i++) {
        TextBufferArray buf;
        watch.reset();
        
        for (char c : text) buf.insert(c);
        buf.moveLeft(); buf.moveLeft(); buf.moveLeft(); buf.moveLeft(); buf.moveLeft();
        buf.insert('X');
        buf.remove();
        buf.remove();
        buf.remove();
        buf.moveRight();
        buf.moveRight();
        buf.insert('Y');
        
        arrayStackTotal += watch.elapsedTime();
    }
 
    for(int i = 0; i < 1000; i++) {
        TextBufferList buf;
        watch.reset();
        
        for (char c : text) buf.insert(c);
        buf.moveLeft(); buf.moveLeft(); buf.moveLeft(); buf.moveLeft(); buf.moveLeft();
        buf.insert('X');
        buf.remove();
        buf.remove();
        buf.remove();
        buf.moveRight();
        buf.moveRight();
        buf.insert('Y');
        
        linkedListStackTotal += watch.elapsedTime();
    }

    std::cout << "Average time for ArrayStack (1000 iterations): " << arrayStackTotal/1000 << " seconds" << std::endl;
    std::cout << "Average time for LinkedListStack (1000 iterations): " << linkedListStackTotal/1000 << " seconds" << std::endl;

    return 0;
}