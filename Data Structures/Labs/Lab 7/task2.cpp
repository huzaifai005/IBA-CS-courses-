#include "red-black-bst.hpp"
#include<iostream>
#include<vector>

int findClosestKey(RedBlackBST<int, std::string>& tree, int target) {
    if(tree.isEmpty()) {
    throw std::out_of_range("Tree is empty");
    }
    std::vector<int> inorder;
    tree.keys(inorder);
    int closest = inorder[0];
    int benchmark = std::abs(inorder[0] - target);
    for(int i = 1; i < inorder.size(); i++) {
        int difference = std::abs(inorder[i] - target);
        if(difference < benchmark) {
            benchmark = difference;
            closest = inorder[i];
        }
    }
    return closest;
}

int main() {
    RedBlackBST<int, std::string> tree;
    tree.put(10, "a");
    tree.put(5, "b");
    tree.put(15, "c");
    tree.put(3, "d");
    tree.put(8, "e");
    std::cout << "closest key to 9: " << findClosestKey(tree, 9) << std::endl;
    std::cout << "closest key to 14: " << findClosestKey(tree, 14) << std::endl;
    std::cout << "closest key to 2: " << findClosestKey(tree, 2) << std::endl;
    
}