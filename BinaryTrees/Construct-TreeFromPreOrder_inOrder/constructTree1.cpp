// For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. 
// You just need to construct the tree and return the root.


#include <iostream>
#include <queue>
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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

BinaryTreeNode<int>* buildTreeHelper(int* preOrder, int preOrderStartIndex, int preOrderEndIndex, int* inOrder, int inOrderStartIndex, int inOrderEndIndex) {
    // base case
    if (preOrderStartIndex > preOrderEndIndex) {
        return nullptr;
    }

    // initialised root’s index to -1 and searched for it’s value in inorder list
    int rootIndex {-1};

    // search for index in inOrder[] that matches with preOrder[startindex]
    for (int i{inOrderStartIndex}; i <= inOrderEndIndex; ++i) {
        if (inOrder[i] == preOrder[preOrderStartIndex]) {
            rootIndex = i;
            break;
        }
    }

    // Initializing the left subtree’s indices for recursive call
    int leftPreOrderStart {preOrderStartIndex + 1};
    int leftInOrderStart {inOrderStartIndex};
    int leftInOrderEnd {rootIndex - 1};
    int leftPreOrderEnd {leftPreOrderStart + (leftInOrderEnd - leftInOrderStart)};

    // Initializing the right subtree’s indices for recursive call
    int rightPreOrderStart {leftPreOrderEnd + 1};
    int rightPreOrderEnd {preOrderEndIndex};
    int rightInOrderStart {rootIndex + 1};
    int rightInOrderEnd {inOrderEndIndex};

    // create current root node
    BinaryTreeNode<int> *root {new BinaryTreeNode<int> (preOrder[preOrderStartIndex])};

    // recuresive cale for left child
    root->left = buildTreeHelper(preOrder, leftPreOrderStart, leftPreOrderEnd, inOrder, leftInOrderStart, leftInOrderEnd);
    root->right = buildTreeHelper(preOrder, rightPreOrderStart, rightPreOrderEnd, inOrder, rightInOrderStart, rightInOrderEnd);

    return root;
}

// this is the function called from the main() with inorder and preorder traversals in the form of arrays and their size which is obviously same for both
// These arguments are of the form (inorder_array, preorder_array, inorder_start, inorder_end, preorder_start, preorder_end) in the helper function for the same written above.
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return buildTreeHelper(preorder, 0, preLength - 1, inorder, 0, inLength - 1);
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);

    return 0;
}

