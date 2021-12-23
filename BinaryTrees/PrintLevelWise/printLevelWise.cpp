// For a given a Binary Tree of type integer, print the complete information of every node, when traversed in a level-order fashion.
// To print the information of a node with data D, you need to follow the exact format :
//            D:L:X,R:Y
// Where D is the data of a node present in the binary tree. 
// X and Y are the values of the left(L) and right(R) child of the node.
// Print -1 if the child doesn't exist.


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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
	queue<BinaryTreeNode<int> *> pendingNode;
    pendingNode.push(root);

    while (pendingNode.size()) {
        BinaryTreeNode<int> *currentNode = pendingNode.front();
        pendingNode.pop();

        cout << currentNode->data << ":";
        
        cout << "L: ";
        if (currentNode->left) {
            cout << currentNode->left->data;
            pendingNode.push(currentNode->left);
        }
        else {
            cout << "-1";
        }

        cout << ",R:";
        if (currentNode->right) {
            cout << currentNode->right->data;
            pendingNode.push(currentNode->right);
        }
        else {
            cout << "-1";
        }
        
        cout << endl;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);

    return 0;
}

