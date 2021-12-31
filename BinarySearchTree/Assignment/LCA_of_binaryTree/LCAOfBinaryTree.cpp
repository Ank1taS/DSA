// -------LCA(Lowest Common Ancestor) of Binary Tree---------

// Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
// LCA
// LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 


/*Example:
In this example, the (*) node is the LCA to A and B.
            ()

        (*)      ()

    (A)      ()

                (B)
*/


// Note:
// It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.
/* Example:
            ()

        (Y)      ()

    (X)      ()    
*/

// Note:
// 1. If out of 2 nodes only one node is present, return that node. 
// 2. If both are not present, return -1.

/******************************************************************************************************************/


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

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // base case
    // if root is null neither a nor b is found, return -1
    if (!root) {
        return -1;
    }

    // if root data is either a or b then return root because alternet node might be it child but root will always be the superior parent or LCA
    if (root->data == a || root->data == b) {
        return root->data;
    }

    // recursive call to left child and right child and store their return value in separate variable
    int leftData {getLCA(root->left, a, b)};
    int rightData {getLCA(root->right, a, b)};

    // if both left and right data are -1 then a and b is not found so return -1
    if (leftData == -1 && rightData == -1) {
        return -1;
    }
    // if either of left or right data is not -1 that means that child have the LCA node return it as it is
    else if (leftData != -1 && rightData == -1) {
        return leftData;
    }
    else if (leftData == -1 && rightData != -1) {
        return rightData;
    }
    // if both left and right data are not -1 then current node is the LCA . so return data at root
    else if (leftData != -1 && rightData != -1) {
        return root->data;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;

    return 0;
}
