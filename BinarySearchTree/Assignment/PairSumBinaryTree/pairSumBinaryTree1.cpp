// Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
// Note:
// 1. Assume the given binary tree contains all unique elements.
// 2. In a pair, print the smaller element first. Order of different pairs doesn't matter.



#include <iostream>
#include <queue>
#include <algorithm>
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

// pre order traversal
void preTraverse(BinaryTreeNode<int> *root, vector<int> &vec) {
    if (!root) {
        return;
    }

    vec.push_back(root->data);

    preTraverse(root->left, vec);
    preTraverse(root->right, vec);

}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int> vec;
    preTraverse(root, vec);

    sort(vec.begin(), vec.end());

    auto begin {0};
    auto end {vec.size() - 1};

    while (begin < end) {
        if (vec.at(begin) + vec.at(end) == sum) {
            cout << vec.at(begin) << " " << vec.at(end) << endl;
            ++begin;
            --end;
        }
        else if (vec.at(begin) + vec.at(end) < sum) {
            ++begin;
        }
        else if (vec.at(begin) + vec.at(end) > sum) {
            --end;
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}