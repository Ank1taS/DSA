// Given a binary tree, check if it is balanced. 
// Return true if given binary tree is balanced, false otherwise.

// Balanced Binary Tree:
// A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
// 1. The left and right subtrees must be balanced.
// 2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    

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

pair<int, bool> isBalancedHelper(BinaryTreeNode<int> *root) {
    // base case   
    if (!root) {
        return {0, true};
    }

    // recursive call to leftchild and rightchild
    pair<int, bool> leftPair {isBalancedHelper(root->left)};
    pair<int, bool> rightPair {isBalancedHelper(root->right)};

    // if either of child's second data ie balance is false then tree is not balance so return false to parent
    if (!(leftPair.second && rightPair.second)) {
        return {0, false};
    }

    // the difference between left child and right child height is more than 1 or less then -1 tree is not balanced return false
    if (leftPair.first - rightPair.first < -1 || leftPair.first - rightPair.first > 1) {
        return {0, false};
    }

    // if either of above is not true then tree is in balance condition.
    // so return max height of left and right + 1 and true 
    return {max(leftPair.first, rightPair.first) + 1, true};
}

bool isBalanced(BinaryTreeNode<int> *root) {
    return isBalancedHelper (root).second;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");

    return 0;
}

