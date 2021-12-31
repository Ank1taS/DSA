// BST class
#include "binaryTreeNode.h"
#include <iostream>

class BST {
    // Define the data members
    BinaryTreeNode<int> *node;

    // print helper() 
    void print(BinaryTreeNode<int> * root) {
        if (!root) {
            return;
        }

        std::cout << root->data << ":";

        if (root->left) {
            std::cout << "L:" << root->left->data << ",";
        }

        if (root->right) {
            std::cout << "R:" << root->right->data;
        }

        std::cout << std::endl;

        print(root->left);
        print(root->right);

    }

    // search helper()
    bool search(BinaryTreeNode<int> *root, int data) {
        if (!root) {
            return false;
        }

        if (root->data == data) {
            return true;
        }
        else if (root->data < data) {
            return search(root->left, data);
        }
        else if (root->data > data) {
            return search(root->right, data);
        }
    }

    // insert helper()
    BinaryTreeNode<int>* insert(BinaryTreeNode<int> *root, int data) {
        if (!root) {
            BinaryTreeNode<int> *newNode {new BinaryTreeNode<int> (data)};

            return newNode;
        }

        if (data <= root->data) {
            root->left = insert(root->left, data);
        }
        else if (data > root->data) {
            root->right = insert(root->right, data);
        }

        return root;
    }
    
    BinaryTreeNode<int>* remove(BinaryTreeNode<int> *root, int data) {
        if (!root) {
            return nullptr;
        }

        if (root->data == data) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr && root->right) {
                BinaryTreeNode<int> *newNode {root->right};
                root->right = nullptr;
                delete root;
                
                return newNode;
            }
            else if (root->left && root->right == nullptr) {
                BinaryTreeNode<int> *newNode {root->left};
                root->left = nullptr;
                delete root;
                
                return newNode;
            }
            else {
                // by taking max data node from left child tree
                /* BinaryTreeNode<int> *newNode {root->left};

                while(newNode->right) {
                    newNode = newNode->right;
                }

                root->data = newNode->data;
                root->left = remove(root->left, newNode->data);
                */

                // by taking min data node from right child tree
               BinaryTreeNode<int> *newNode {root->right};

                while (newNode->left) {
                    newNode = newNode->left;
                }

                root->data = newNode->data;
                root->right = remove(newNode->right, newNode->data);

                return root; 
            }
        }
        else if (data < root->data) {
            root->left = remove(root->left, data);
        }
        else if (data > root->data) {
            root->right = remove(root->right, data);
        }

    }

    /*----------------- Public Functions of BST -----------------*/
public:
    // Implement the Constructor
    BST() { 
        node = nullptr;
    }

    // destructor
    ~BST() {
        delete node;
    }

    // Implement the remove() function 
    void remove(int data) { 
        node = remove(node, data);
    }

    // Implement the print() function
    void print() { 
        print(node);
    }

    // Implement the insert() function 
    void insert(int data) { 
        node = insert(node, data);
    }

    // Implement the search() function 
    bool search(int data) {
        return search(node, data);
    }
};