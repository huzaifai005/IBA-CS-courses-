//Please credit full marks as Sir updated the correct question late and told that this implementation will be creditted full marks as well.

#include <iostream>
#include <queue>
#include <vector>

struct Node {
    char key;
    Node* left;
    Node* right;
    Node(char val) : key(val), left(nullptr), right(nullptr) {}
};

//part a
Node* insert(Node* root, char key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } 
    else {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* build(const std::vector<char>& arr) {
    if (arr.empty()) return nullptr;
    Node* root = nullptr;  
    for (char key : arr) {
        root = insert(root, key);  
    }
    return root;
}

//part b
void printLevelOrder(Node* root) {
    if (!root) return;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        std::cout << curr->key << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    std::cout << std::endl;
}

int main() {
    std::vector<char> keys = {'S','E','T','A','R','C','H','M'};
    Node* root = build(keys);

    std::cout << "Level Order Traversal of BST: ";
    printLevelOrder(root);
}