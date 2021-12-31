// Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
// Note: Assume that BST contains all unique elements.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;


template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

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


BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
    // a empty vector - vec
    vector<int> *vec {new vector<int>()};

    //base case
    // if root is null, element is not found return empty vec 
    if (!root) {
        return vec;
    }

    // current node data same as data , put current node data to the empty vector vec
    if (root->data == data) {
        vec->push_back(data);
    }
    // if data is smaller then the root data that mean no need to call for right child(as it would only contain greater data)
    else if (data < root->data) {
        // so recursive call to left child
        vec = getPath(root->left, data);
        // if vec is not empty that mean already nodes are present in vector to add path add current node to it
        if (!vec->empty()) {
            vec->push_back(root->data);
        }
    }
    // if data is greater than the root data that mean no need to call for left child(as it would only contain smaller data)
    else {
        // so recursive call to right child
        vec = getPath(root->right, data);
        // if vec is not empty that mean already nodes are present in vector to add path add current node to it
        if (!vec->empty()) {
            vec->push_back(root->data);
        }
    }

    // return vec (either empty or contain left or right path)
    return vec;
    
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}
