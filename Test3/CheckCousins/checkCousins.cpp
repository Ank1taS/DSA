#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

pair<BinaryTreeNode<int>*, int> helper(BinaryTreeNode<int>* root, int element) {
    pair<BinaryTreeNode<int>*, int> finalAns {nullptr, 0};

    if (!root || (root->left == nullptr && root->right == nullptr)) {
        return finalAns;
    }

    if (root->left) {
        if (root->left->data == element) {
            return {root, 1};
        }
    }
    else if (root->right) {
        if (root->right->data == element) {
            return {root, 1};
        }
    }


    pair<BinaryTreeNode<int>*, int> leftAns {helper(root->left, element)};
    if (leftAns.first != nullptr) {
        finalAns.first = leftAns.first;
        finalAns.second= leftAns.second + 1;
        return finalAns;
    }

    pair<BinaryTreeNode<int>*, int> rightAns {helper(root->right, element)};
    if (rightAns.first != nullptr) {
        finalAns.first = rightAns.first;
        finalAns.second= rightAns.second + 1;
        return finalAns;
    }

    return finalAns;
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    pair<BinaryTreeNode<int>*, int> pPair { helper(root, p)};
    pair<BinaryTreeNode<int>*, int> qPair { helper(root, q)};

    if (pPair.first != nullptr && qPair.first != nullptr) {
        if (pPair.second == qPair.second) {
            if (pPair.first != qPair.first) {
                return true;
                
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}
