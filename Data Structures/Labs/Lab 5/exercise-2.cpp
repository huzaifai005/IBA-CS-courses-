#include<iostream>
#include<vector>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

// Helper function for size calculations
int size(Node* root) {
    if (root == nullptr) {
    return 0;
    }
    return 1 + size(root->left) + size(root->right);
}

//for testing purposes
Node* insert(Node* root, int key) {
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

//part a
int height(Node* root) {
    if(root == nullptr) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(leftHeight > rightHeight) {
        return 1 + leftHeight;
    }
    else {
        return 1 + rightHeight;
    }   
}

// part b
int sizeOdd(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int count = 0;
    if (root->key % 2 == 1) {
        return 1 + sizeOdd(root->left) + sizeOdd(root->right);
    }
    else {
        return sizeOdd(root->left) + sizeOdd(root->right);
    }
}

// part c
bool isPerfectlyBalancedH(Node* root) {
    if(root == nullptr) {
        return true;
    }
    if(height(root->left) == height(root->right)) {
        return isPerfectlyBalancedH(root->left) && isPerfectlyBalancedH(root->right);
    }
    else {
        return false;
    }
}

// part d
bool isSemiBalancedI(Node* root) {
    if(root == nullptr) {
        return true;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return true;
    }
    if(size(root->right) > size(root->left)) {
        if((double)size(root->right)/size(root->left) <= 2) {
            return isSemiBalancedI(root->left) && isSemiBalancedI(root->right);
        }
    }
    else if (size(root->left) > size(root->right)) {
        if((double)size(root->left)/size(root->right) <= 2) {
            return isSemiBalancedI(root->left) && isSemiBalancedI(root->right);
        }
    }
    else {
        return isSemiBalancedI(root->left) && isSemiBalancedI(root->right);
    }
    return false;
}

// part e
int sizeAtDepth(Node* root, int depth) {
    if(root == nullptr || depth < 0) {
        return 0;
    }
    if (depth == 0) {
        return 1;
    }
    return sizeAtDepth(root->left, depth - 1) + sizeAtDepth(root->right, depth - 1);
}

// part f
int sizeAboveDepth(Node* root, int depth) {
    if(root == nullptr || depth < 0) {
        return 0;
    }
    if (depth > 0) {
        return 1 + sizeAboveDepth(root->left, depth - 1) + sizeAboveDepth(root->right, depth - 1);
    }
    return 0;
}

// part g
int sizeBelowDepth(Node* root, int depth, int currentDepth = 0) {
    if(root == nullptr) {
        return 0;
    }
    if(currentDepth > depth) {
        return 1 + sizeBelowDepth(root->left, depth, currentDepth + 1) 
                 + sizeBelowDepth(root->right, depth, currentDepth + 1);
    }
    return sizeBelowDepth(root->left, depth, currentDepth + 1) 
         + sizeBelowDepth(root->right, depth, currentDepth + 1);
}

//traversal
void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    std::cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    std::vector<int> values = {9, 7, 11, 10, 8, 6, 5, 20};
    for (int v : values) root = insert(root, v);

    std::cout << "Size below depth 1: " << sizeBelowDepth(root, 1) << "\n";
    std::cout << "Is semi-balanced? " << isSemiBalancedI(root)<< " (1 means true and 0 is false)."<<"\n";
    
    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << "\n";

    std::cout << "Number of odd keys: " << sizeOdd(root) << "\n";
    std::cout << "Size above depth 2: " << sizeAboveDepth(root, 2) << "\n";
    
    std::cout << "Height: " << height(root) << "\n";
    std::cout << "Is perfectly balanced (height)? " << isPerfectlyBalancedH(root) << " (1 means true and 0 is false)." << "\n";
    
    std::cout << "Size at depth 2: " << sizeAtDepth(root, 2) << "\n";

}

