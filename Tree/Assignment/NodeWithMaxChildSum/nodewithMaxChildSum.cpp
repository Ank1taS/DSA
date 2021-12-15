// Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. 
// In the sum, data of the node and data of its immediate child nodes has to be taken.

// time complexity - O(N ^ 3)

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

class NodePair {
    public:
    TreeNode<int> *node;
    int sum;

    NodePair(TreeNode<int> *node, int sum)
        : node {node}, sum {sum} {}

};

NodePair* helper(TreeNode<int> *root) {
    int sum = root->data;

    for (auto child : root->children) {
        sum += child->data;
    }

    NodePair *node = new NodePair(root, sum);

    return node;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int> *node {root};
    int sum {root->data};

    std::queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);

    for (auto child : root->children) {
        sum += child->data;
    }

    while(pendingNode.size()) {
        TreeNode<int> *currentNode {pendingNode.front()};
        pendingNode.pop();
        
        for (auto child : currentNode->children) {
            pendingNode.push(child);
            NodePair *maxNode {helper(child)};

            if (sum < maxNode->sum) {
                sum = maxNode->sum;
                node = maxNode->node;
            }
        }
    }

    return node;
}

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

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}