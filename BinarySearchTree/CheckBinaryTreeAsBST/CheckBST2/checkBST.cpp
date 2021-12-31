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

class IsBSTReturn {
public:
    bool isBST;
    int maximum;
    int minimum;

    IsBSTReturn (bool isBST = true, int maximum = INT_MIN , int minimum = INT_MAX) 
     : isBST {isBST}, maximum {maximum}, minimum {minimum} {}
};

IsBSTReturn isBSTHelper(BinaryTreeNode<int> *root) {
    IsBSTReturn outPut;     // set default value
    
    if (!root) {
        return outPut;
    }

	IsBSTReturn leftOutPut {isBSTHelper(root->left)};
	IsBSTReturn rightOutPut {isBSTHelper(root->right)};

	int maximum {max(root->data, max(leftOutPut.maximum, rightOutPut.maximum))};
	int minimum {min(root->data, min(leftOutPut.minimum, rightOutPut.minimum))};
	bool BST {(root->data > leftOutPut.maximum) && (root->data <= rightOutPut.minimum) && leftOutPut.isBST && rightOutPut.isBST};

	outPut.maximum = maximum;
	outPut.minimum = minimum;
	outPut.isBST = BST;

	return outPut;
}

bool isBST(BinaryTreeNode<int> *root) {
    return isBSTHelper(root).isBST;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	cout << isBST(root) << endl;
	delete root;

	return 0;
}

