// For a given Binary Tree of type integer, print all the nodes without any siblings.


#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    // base case
    if (!root) {
        return;
    }
    
    // check if root node contain only left node then print the left node as its sibling right node is null
    if(root->left && !root->right) {
        cout << root->left->data << " ";
    }
    
    // check if root node contain only right node then print the right node as its sibling leftt node is null
    if(!root->left && root->right) {
        cout << root->right->data << " ";
    }
    
    // recursive call to left child node if it is not null
    if (root->left) {
        printNodesWithoutSibling(root->left);
    }
    // recursive call to right child node if it is not null
    if (root->right) {
        printNodesWithoutSibling(root->right);
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printNodesWithoutSibling(root);
}