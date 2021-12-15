// Given a generic tree, print the input tree in level wise order.
// For printing a node with data N, you need to follow the exact format -
// N:x1,x2,x3,...,xn
// where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn are the children of node N. Note that there is no space in between.
// You need to print all nodes in the level order form in different lines.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    std::vector<TreeNode<T> *> children;

    // constructor
    TreeNode(T data) : data{data} {}

    // destructor
    ~TreeNode() {
        for (auto i : children) {
            delete i;
        }
//         for (int i = 0; i < children.size(); i++) {
//             delete children[i];
        // }
    }
};


// to take input level wise

TreeNode<int>* takeInputLevelWise() {
    int data;
    cout << "Enter Root Node data : ";
    cin >> data;
    TreeNode<int> *rootNode = new TreeNode<int>(data);

    std::queue<TreeNode<int> *> pendingNode;
    pendingNode.push(rootNode);

    while (pendingNode.size()) {
        TreeNode<int> *currentNode = pendingNode.front();
        pendingNode.pop();

        int childerCount;
        cout << "Enter number of childern of " << currentNode->data << " : ";
        cin >> childerCount;

        for (int i {0}; i < childerCount; ++i) {
            int data;

            cout << "Enter data for child [" << i << "] of " << currentNode->data << " : ";
            cin >> data;

            TreeNode<int> *childNode = new TreeNode<int>(data);

            currentNode->children.push_back(childNode);
            pendingNode.push(childNode);
        }
    }
    return rootNode;
}

// to print Nodes level wise
void printLevelWise(TreeNode<int> *root) {
    std::queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);

    while (pendingNode.size()) {
        TreeNode<int> *currentNode = pendingNode.front();
        pendingNode.pop();
        
        cout << currentNode->data << " : ";
        for (auto child : currentNode->children) {
            cout << child->data << ", ";
            pendingNode.push(child);
        }
        cout << endl;
    }

}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);

    return 0;
}



//class TreeNode {
//    public:
//     T data;
//     vector<TreeNode<T>*> children;

//     TreeNode(T data) { this->data = data; }

//     ~TreeNode() {
//         for (int i = 0; i < children.size(); i++) {
//             delete children[i];
//         }
//     }
// };