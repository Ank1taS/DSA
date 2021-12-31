// Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
// That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
// Note: You don't need to return or print, just change the data of each node.


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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
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

// helper function - overloaded replaceWithLargerNodesSum() 
// traverse in reverse inOrder ie right-root-left 
int replaceWithLargerNodesSum(BinaryTreeNode<int>* root, int sum) {
    // base case 
    // for root node return sum sould be 0
    if (!root) {
        return 0;
    }

    // recursive call to right child with sum as parameter
    int rightSum {replaceWithLargerNodesSum(root->right, sum)};

    // store root dtata in temp varriable
    int rootDataTemp {root->data};
    // as nodes present at the right of root are greater so their sum + root data + parameter sum is added and stored in root 
    root->data += rightSum + sum;

    // for left child , root and root's right data have greater data so pass parameter sum + root Data + right sum as parameter 
    int leftSum {replaceWithLargerNodesSum(root->left, sum + rootDataTemp + rightSum)};

    // return leftSum + rootdata + right sum to parent node; 
    int totalSum {leftSum + rootDataTemp + rightSum};
    return totalSum;
}


void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // helper function
    int sum {replaceWithLargerNodesSum(root, 0)};
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    replaceWithLargerNodesSum(root);
    printLevelATNewLine(root);
    delete root;

    return 0;
}