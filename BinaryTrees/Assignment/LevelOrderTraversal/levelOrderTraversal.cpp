// For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.
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

void printLevelWise(BinaryTreeNode<int> *root) {
    // edge case
    if (!root) {
        return;
    }

    // queue to store nodes present in each node followed by nullptrs
    queue<BinaryTreeNode<int>*> pendingNode;

    // store root 
    pendingNode.push(root);
   // a nullptr as mark of end of level 1
    pendingNode.push(nullptr);

    while (pendingNode.size()) {
        // store front elemnt of queqe in currentNode
        BinaryTreeNode<int> *currentNode {pendingNode.front()};

        // if current node is nullptr it marks end of a level
        if (currentNode == nullptr) {
            // if there is still elements after the currentNode nullptr that means it is not the end of queue 
            // then print newline then push a nullptr to the end of queue
            if (pendingNode.size() != 1) {
                cout << endl;
                pendingNode.push(nullptr);
            } 
        }
        else {      // if it is not nullptr then it is a tree node
            // print tree node 
            cout << currentNode->data << " ";

            // push it's left child if exists
            if (currentNode->left) {
                pendingNode.push(currentNode->left);
            }
            // push it's right child if exists
            if (currentNode->right) {
                pendingNode.push(currentNode->right);
            }
        }
        // pop the currentNode from queue
        pendingNode.pop();
    }    
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);

    return 0;
}