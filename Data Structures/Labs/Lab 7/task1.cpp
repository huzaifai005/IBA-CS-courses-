#include "red-black-bst.hpp"
#include<iostream>
#include<vector>

int countInRange(RedBlackBST<int, std::string>& tree, int low, int high) {
    if(tree.isEmpty()) {
    throw std::out_of_range("Tree is empty");
    }
    int count = 0;
    std::vector<int> inorder;
    tree.keys(inorder);
    for(int i = 0; i < inorder.size(); i++) {
        if(inorder[i] >= low && inorder[i] <= high) {
            count = count + 1;
        }
    }
    return count;

}

int main() {
    RedBlackBST<int, std::string> tree;
    std::vector<int> traverse;
    tree.put(10, "a");
    tree.put(5, "b");
    tree.put(15, "c");
    tree.put(3, "d");
    tree.put(8, "e");
    tree.keys(traverse);
    std::cout << "Keys in sorted order: ";
    for(int i = 0; i < traverse.size(); i++) {
        std::cout << traverse[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Count of keys in [5, 12]: " << countInRange(tree, 5, 12);
    

}
