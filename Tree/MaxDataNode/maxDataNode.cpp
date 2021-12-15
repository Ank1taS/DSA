// Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
// Return null if tree is empty.

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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if (!root) {
        return nullptr;
    }

    int max {0};
    TreeNode<int> *maxNode {nullptr};

    std::queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);

    max = root->data;
    maxNode = root;

    while (pendingNode.size()) {
        TreeNode<int> *currentNode = pendingNode.front();
        pendingNode.pop();

        for (auto child: currentNode->children) {
            pendingNode.push(child);
            if (max < child->data) {
                max = child->data;
                maxNode = child;
            }
        }
    }

    return maxNode;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);

    if (root != NULL) {
        cout << ans->data;
    }

    return 0;
}
