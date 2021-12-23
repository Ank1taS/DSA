// Given a binary tree, print the zig zag order. 
// In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. 
// This means odd levels should get printed from left to right and even level right to left.


#include <iostream>
#include <stack>
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

void zigZagOrder(BinaryTreeNode<int> *root) {
    if (!root) {
        return;
    }

    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;

    s1.push(root);

    while(s1.size() || s2.size()) {
        
        if (s1.size()) {
            while (s1.size()) {
                BinaryTreeNode<int> *currentNode {s1.top()};
                s1.pop();

                cout << currentNode->data << " ";

                if (currentNode->left) {
                    s2.push(currentNode->left);
                }

                if (currentNode->right) {
                    s2.push(currentNode->right);
                }
            }
            cout << endl;
        }

        if (s2.size()) {
            while (s2.size()) {
                BinaryTreeNode<int> *currentNode {s2.top()};
                s2.pop();

                cout << currentNode->data << " ";

                if (currentNode->right) {
                    s1.push(currentNode->right);
                }

                if (currentNode->left) {
                    s1.push(currentNode->left);
                }
            }
            cout << endl;
        }
    }

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);

    return 0;
}

