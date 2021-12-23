// Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.


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

void printLevelATNewLine(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}


BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // base case
    if (!root) {
        return nullptr;
    }
    
    // if root node dont have left and right child node then it is a leaf node. Delete it and return null to its parent node 
    if (!root->left && !root->right) {
        delete root;
        return nullptr;
    }
    
    // if root's left node is not null recursive call to left node 
    if(root->left) {
        root->left = removeLeafNodes(root->left);
    }
    
    // if root's right node is not null recursive call to right node 
    if(root->right) {
        root->right = removeLeafNodes(root->right);
    }
    
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    root = removeLeafNodes(root);
    printLevelATNewLine(root);
}
