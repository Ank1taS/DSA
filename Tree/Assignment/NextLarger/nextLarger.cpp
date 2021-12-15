// Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
// // Note: Return NULL if no node is present with the value greater than n.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // edge case
    if (!root) {
        return nullptr;
    }

    TreeNode<int> * nextLargestNode {nullptr};

    if (root->data > x) {
        nextLargestNode = root;
    }

    // recursive call for succesive children
    for (auto child : root->children) {
        TreeNode<int> *temp = getNextLargerElement(child, x);

        if (!nextLargestNode) { 
            nextLargestNode = temp;
        }
        else if (temp != nullptr && temp->data < nextLargestNode->data) {
            nextLargestNode = temp;
        }
        
    }

    return nextLargestNode;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}
