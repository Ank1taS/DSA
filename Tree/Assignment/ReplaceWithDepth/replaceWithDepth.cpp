// You are given a generic tree. You have to replace each node with its depth value. 
// You just have to update the data of each node, there is no need to return or print anything.


#include <climits>
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

void printLevelATNewLine(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode<int>* first = q.front();
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
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}

// helper function to replace node value with its depth
void helper(TreeNode<int> *root, int depth) {
    // replace root data value with depth value
    root->data = depth;

    // recursive call for childern
    for (auto child : root->children) {
        helper(child, depth + 1);
    }
}

// function to replace node value with its depth
void replaceWithDepthValue(TreeNode<int>* root) {
    // edge case
    if (!root) {
        return;
    }

    return helper(root, 0);
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    replaceWithDepthValue(root);
    printLevelATNewLine(root);

    return 0;
}
