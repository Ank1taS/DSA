// Given two generic trees, return true if they are structurally identical. Otherwise return false.



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
    cout << "Enter root data : ";
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNode;
    pendingNode.push(root);

    while (pendingNode.size()) {
        TreeNode<int> *currentNode {pendingNode.front()};
        pendingNode.pop();

        cout << "Enter Number of children of " << currentNode->data << " : ";
        int childrenCount;
        cin >> childrenCount;

        for (int i {0}; i < childrenCount; ++i) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            currentNode->children.push_back(child);
            pendingNode.push(child);
        }
    }

    return root;
}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // edge case
    if (!root1 || !root2) {
        return false;
    }

    // if either data in both node does not matches or 
    // children nodes count does not matches that means both the tree are not same
    if (root1->data != root2->data || root1->children.size() != root2->children.size()) {
        return false;
    }

    // if both the above case false then recursive call for children nodes
    for (int i {0}; i < root1->children.size(); ++i) {
        areIdentical(root1->children[i], root2->children[i]);
    }

    return true;
}

int main() {
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");

    return 0;
}