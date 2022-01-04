// Given a binary tree, check if it is balanced. 
// Return true if given binary tree is balanced, false otherwise.


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
    if (!root) {
        return {0, true};
    }

    pair<int, bool> leftPair {isBalancedHelper(root->left)};
    pair<int, bool> rightPair {isBalancedHelper(root->right)};
    pair<int, bool> answer;

    int minHeight {min(leftPair.first, rightPair.first)};
    int maxHeight {max(leftPair.first, rightPair.first)};

    if (leftPair.second == true && rightPair.second == true) {
        if (maxHeight - minHeight <= 1) {
            answer.second = true;
        }
        else {
            answer.second = false;
        }
    }
    else {
        answer.second = false;
    }

    answer.first = maxHeight + 1;
    return answer;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    return isBalancedHelper (root).second;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");

    return 0;
}

