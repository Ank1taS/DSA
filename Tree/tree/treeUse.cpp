#include <iostream>
#include <queue>
#include "treeNode.h"
// template class TreeNode<int>;


template<typename T>
TreeNode<T>* takeInputLevelwise() {
    int rootData;
    std::cout << "Enter root data: ";
    std::cin >> rootData;

    TreeNode<T>* root {new TreeNode<T>(rootData)};

    std::queue<TreeNode<T>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.empty() == 0) {
        TreeNode<T>* front {pendingNodes.front()};
        pendingNodes.pop();

        std::cout << "Enter number of children of " << front->data << ": ";
        int childrenNumbers;
        std::cin >> childrenNumbers;

        for (int i {0}; i < childrenNumbers; ++i) {
            std::cout << "enter data for child - " << i + 1 << ": ";
            T childData;
            std::cin >> childData;

            TreeNode<T>* childNode {new TreeNode<T>(childData)};
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}

template<typename T>
void printTree(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << ": ";
    // print children nodes
    for (int i {0}; i < root->children.size(); ++i) {
        std::cout << root->children.at(i)->data << " ";
    }
    std::cout << std::endl;

    // recursive call to children nodes
    for (int i {0}; i < root->children.size(); ++i) {
        printTree(root->children.at(i));
    }

}

int main() {
    TreeNode<int>* root {takeInputLevelwise<int>()};

    printTree(root);
    delete root;

    return 0;
}
