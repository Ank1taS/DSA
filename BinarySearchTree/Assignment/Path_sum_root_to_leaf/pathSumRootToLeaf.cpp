// For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.
// Example:
        // k = 13

        //                 (2)
        //             /       \
        //         (3)           (9)
        //         /   \           \
        //     (4)     (8)           (2)
        //     /                     /
        // (4)                     (6)
            

// If you see in the above-depicted picture of Binary Tree, we see that there are a total of two paths, starting from the root and ending at the leaves which sum up to a value of K = 13.

// The paths are:
// a. 2 3 4 4
// b. 2 3 8

// One thing to note here is, there is another path in the right sub-tree in reference to the root, which sums up to 13 but since it doesn't end at the leaf, we discard it.
// The path is: 2 9 2(not a leaf)

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <queue>
#include <string>
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

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, string str) {
    // base case
    // if root is null or k <= 0 then no further checks or operation needed
    if (!root || k <= 0) {
        return;
    }

    // substract root data from k and update it
    k -= root->data;
    // add root data to the string
    str += std::to_string(root->data);
    str += " ";

    // if k == 0 after substraction that mean after this node no furthere operation needed
    if (k == 0) {
        // if the current node is the leaf node then print the str other wise return to parent node
        if (root->left == nullptr && root->right == nullptr) {
            cout << str << endl;
        }
        return;
        
    }

    // recursive call to left and right child with updated k and str
    rootToLeafPathsSumToK(root->left, k, str);
    rootToLeafPathsSumToK(root->right, k, str);

}


void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    rootToLeafPathsSumToK(root, k, "");
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;

    return 0;
}