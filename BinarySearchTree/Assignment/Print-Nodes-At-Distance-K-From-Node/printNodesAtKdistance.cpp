// Print nodes at distance k from node
// Send Feedback
// You are given a Binary Tree of type integer, a target node, and an integer value K.
// Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.

// Example:
// For a given input tree(refer to the image below):
// 1. Target Node: 5
// 2. K = 2
//                         3

//                 (5)               (1)

//             6       2       0       8

//                 (7)       (4)

// Starting from the target node 5, the nodes at distance K are 7 4 and 1.

//---------------------------------------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};


BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printNodeAtKDistance(BinaryTreeNode<int>* root, int k) {
    if (!root) {
        return;
    }

    if (k == 0) {
        cout << root->data << endl;
        return;
    }

    printNodeAtKDistance(root->left, k - 1);
    printNodeAtKDistance(root->right, k - 1);

}
 

int nodesAtDistanceKHelper(BinaryTreeNode<int>* root, int node, int k) {
    if (!root) {
        return -1;
    }

    if (root->data == node) {
        // cout << root->data << " ";
        printNodeAtKDistance(root, k);
        return 0;
    }

    int leftDistance {nodesAtDistanceKHelper(root->left, node, k)};

    if (leftDistance != -1) {
        if (leftDistance + 1 == k) {
            cout << root->data << " ";
            
        }
        else {
            printNodeAtKDistance(root->right, k - leftDistance - 2);
        }
        return leftDistance + 1;
    }

    int rightDistance {nodesAtDistanceKHelper(root->right, node, k)};

    if (rightDistance != -1) {
        if (rightDistance + 1 == k) {
            cout << root->data << " ";
            
        }
        else {
            printNodeAtKDistance(root->left, k - rightDistance - 2);
        }
        return rightDistance + 1;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    int value {nodesAtDistanceKHelper(root, node, k)};
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
