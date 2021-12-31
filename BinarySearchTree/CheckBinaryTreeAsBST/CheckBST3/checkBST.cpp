// time complexity is   O(n * h) worst
//						O(n logn)

#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <climits>
using namespace std;

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	// cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		// cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		// cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}


bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX) {
	if (!root) {
		return true;
	}

	if (root->data < min || root->data > max) {
		return false;
	}

	bool leftBST {isBST(root->left, min, root->data - 1)};
	bool rightBST {isBST(root->right, root->data, max)};

	return leftBST && rightBST;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << isBST(root) << endl;
	delete root;

	return 0;
}

