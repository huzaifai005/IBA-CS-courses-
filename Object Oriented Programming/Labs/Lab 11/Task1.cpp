#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FileNode {
public:
    string fileName;
    int fileSize;
    string fileType;
    FileNode* left;
    FileNode* right;

    FileNode(string name, int size, string type) 
        : fileName(name), fileSize(size), fileType(type), left(nullptr), right(nullptr) {}

    friend ostream& operator<<(ostream& os, const FileNode& node) {
        os << "File Name: " << node.fileName << ", Type: " << node.fileType 
           << ", Size: " << node.fileSize << "MB";
        return os;
    }
};

class BinarySearchTree {
private:
    FileNode* root;

    FileNode* insert(FileNode* node, string name, int size, string type) {
        if (node == nullptr) {
            return new FileNode(name, size, type);
        }

        if (name < node->fileName) {
            node->left = insert(node->left, name, size, type);
        } else if (name > node->fileName) {
            node->right = insert(node->right, name, size, type);
        } else {
            throw runtime_error("Duplicate file name: " + name);
        }

        return node;
    }

    FileNode* findMin(FileNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    FileNode* erase(FileNode* node, string name) {
        if (node == nullptr) {
            throw runtime_error("File not found: " + name);
        }

        if (name < node->fileName) {
            node->left = erase(node->left, name);
        } else if (name > node->fileName) {
            node->right = erase(node->right, name);
        } else {
            if (node->left == nullptr) {
                FileNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                FileNode* temp = node->left;
                delete node;
                return temp;
            }

            FileNode* temp = findMin(node->right);
            node->fileName = temp->fileName;
            node->fileSize = temp->fileSize;
            node->fileType = temp->fileType;
            node->right = erase(node->right, temp->fileName);
        }
        return node;
    }

    FileNode* search(FileNode* node, string name) {
        if (node == nullptr || node->fileName == name) {
            return node;
        }

        if (name < node->fileName) {
            return search(node->left, name);
        } else {
            return search(node->right, name);
        }
    }

    void LargeFiles(FileNode* node, int threshold, vector<FileNode*>& result) {
        if (node == nullptr) return;

        LargeFiles(node->left, threshold, result);
        if (node->fileSize > threshold) {
            result.push_back(node);
        }
        LargeFiles(node->right, threshold, result);
    }

    void inorder(FileNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << *node << endl;
        inorder(node->right);
    }

    void preorder(FileNode* node) {
        if (node == nullptr) return;
        cout << *node << endl;
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(FileNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << *node << endl;
    }

    void clear(FileNode* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        clear(root);
    }

    void insert(string name, int size, string type) {
        try {
            root = insert(root, name, size, type);
        } catch (const runtime_error& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void erase(string name) {
        try {
            root = erase(root, name);
        } catch (const runtime_error& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void rename(string oldName, string newName) {
        try {
            FileNode* node = search(root, oldName);
            if (node == nullptr) {
                throw runtime_error("File not found: " + oldName);
            }
            
            int size = node->fileSize;
            string type = node->fileType;
            
            erase(oldName);
            insert(newName, size, type);
        } catch (const runtime_error& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    FileNode* search(string name) {
        return search(root, name);
    }

    vector<FileNode*> LargeFiles(int threshold) {
        vector<FileNode*> result;
        LargeFiles(root, threshold, result);
        return result;
    }

    void inorder() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        inorder(root);
    }

    void preorder() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        preorder(root);
    }

    void postorder() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return;
        }
        postorder(root);
    }
};

int main() {
    BinarySearchTree fileSystem;

    fileSystem.insert("file1.txt", 100, "txt");
    fileSystem.insert("file2.pdf", 200, "pdf");
    fileSystem.insert("file3.exe", 300, "exe");

    cout << "Inorder Traversal:" << endl;
    fileSystem.inorder();
    cout << endl;

    cout << "Preorder Traversal:" << endl;
    fileSystem.preorder();
    cout << endl;

    cout << "Postorder Traversal:" << endl;
    fileSystem.postorder();
    cout << endl;

    cout << "Searching for filed.pdf:" << endl;
    FileNode* found = fileSystem.search("file2.pdf");
    if (found) {
        cout << *found << endl;
    } else {
        cout << "File not found!" << endl;
    }
    cout << endl;

    cout << "Files larger than 150MB:" << endl;
    vector<FileNode*> largeFiles = fileSystem.LargeFiles(150);
    for (FileNode* file : largeFiles) {
        cout << *file << endl;
    }
    cout << endl;

    cout << "Deleting file2.pdf:" << endl;
    fileSystem.erase("filed.pdf");
    
    cout << "Inorder Traversal after deletion:" << endl;
    fileSystem.inorder();
    cout << endl;

    cout << "Searching for file2.pdf after deletion:" << endl;
    found = fileSystem.search("file2.pdf");
    if (found) {
        cout << *found << endl;
    } else {
        cout << "File not found!" << endl;
    }
    cout << endl;

    cout << "Renaming file1.txt to renamed_file4.txt:" << endl;
    fileSystem.rename("file1.txt", "renamed_file4.txt");
    
    cout << "Inorder Traversal after renaming:" << endl;
    fileSystem.inorder();
    cout << endl; 

}