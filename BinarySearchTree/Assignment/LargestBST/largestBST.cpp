// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.

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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
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

class IsBSTReturn {
public:
    bool isBST;
    int maximum;
    int minimum;
    int height;

    IsBSTReturn (bool isBST = true, int maximum = INT_MIN , int minimum = INT_MAX, int height = 0) 
     : isBST {isBST}, maximum {maximum}, minimum {minimum}, height {height} {}
};

IsBSTReturn* largestBSTSubtreeHelper(BinaryTreeNode<int> *root) {
    IsBSTReturn *output {new IsBSTReturn()};

    if (!root) {
        return output;
    }

    IsBSTReturn *leftSubTree {largestBSTSubtreeHelper(root->left)};
    IsBSTReturn *rightSubTree {largestBSTSubtreeHelper(root->right)};

    // if both subtree 
    if (leftSubTree->isBST && rightSubTree->isBST) {

        if (root->data > leftSubTree->maximum && root->data <= rightSubTree->minimum ) {
            output->isBST = true;
            output->height = 1 + max(leftSubTree->height, rightSubTree->height);
        }
        else {
            output->isBST = false;
            output->height = max(leftSubTree->height, rightSubTree->height);
        }

        output->maximum = max(root->data, max(leftSubTree->maximum, rightSubTree->maximum));
        output->minimum = min(root->data, min(leftSubTree->minimum, rightSubTree->minimum));

    }
    // else if (leftSubTree->isBST && !rightSubTree->isBST) {

    // }
    // else if (!leftSubTree->isBST && rightSubTree->isBST) {
    
    // }
    else if (leftSubTree->isBST == false|| rightSubTree->isBST == false) {
        output->isBST = false;
        output->maximum = INT_MAX;
        output->minimum = INT_MIN;
        output->height = max(leftSubTree->height, rightSubTree->height);
        
    }
    return output;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    
    return largestBSTSubtreeHelper(root)->height;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
