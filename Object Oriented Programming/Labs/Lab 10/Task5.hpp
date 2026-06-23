#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <vector>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;

        Node(const T& num) : value(num), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, const T& value) {
        if (!node) {
            node = new Node(value);
        } else if (value < node->value) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    void in_order(Node* node, std::vector<T>& result) const {
        if (!node) return;
        in_order(node->left, result);
        result.push_back(node->value);
        in_order(node->right, result);
    }

    void erase(Node*& node) {
        if (!node) return;
        erase(node->left);
        erase(node->right);
        delete node;
        node = nullptr;
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        clear();
    }

    BinaryTree(const BinaryTree& other) : root(nullptr) {
        std::vector<T> values = other.traverse();
        for (const auto& value : values) {
            insert_val(value);
        }
    }

    BinaryTree& operator=(const BinaryTree& other) {
        if (this != &other) {
            clear();
            std::vector<T> values = other.traverse();
            for (const auto& value : values) {
                insert_val(value);
            }
        }
        return *this;
    }

    void insert_val(const T& value) {
        insert(root, value);
    }

    std::vector<T> traverse() const {
        std::vector<T> result;
        in_order(root, result);
        return result;
    }

    void clear() {
        erase(root);
    }

    std::vector<T> operator()(const std::vector<T>& values) {
        clear();
        for (const auto& value : values) {
            insert_val(value);
        }
        return traverse();
    }
};

#endif 