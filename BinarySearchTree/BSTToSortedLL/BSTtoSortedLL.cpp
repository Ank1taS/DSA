// Given a BST, convert it into a sorted linked list. You have to return the head of LL.


#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

pair<Node<int> *, Node<int> *> constructLinkedListHelper(BinaryTreeNode<int>* root) {
    // base case
    // if root is null then return a pair containing nullptr and nullptr indicating end of tree 
    if (!root) {
        return {nullptr, nullptr};
    }

    // recursive call to left child of the tree and right child of the tree and store the result in 2 pair obj 
    pair<Node<int> *, Node<int> *> leftPair {constructLinkedListHelper(root->left)};
    pair<Node<int> *, Node<int> *> rightPair {constructLinkedListHelper(root->right)};

    // create new node having root data as data for linkedList 
    Node<int> *currentNode {new Node<int> (root->data)};
    
    // if leftLinkedList is empty then current node will be the head and tail of linkedList
    // so set leftpair LL's first and second set to currentnode
    if (leftPair.first == nullptr && leftPair.second == nullptr) {
        leftPair.first = leftPair.second = currentNode;
    }
    // if avove case is false then leftLL have some nodes and we just need to add current new node to the end of LeftLL and left's tail need to point current new node 
    else {
        leftPair.second->next = currentNode;
        leftPair.second = leftPair.second->next;
    }

    // if rightPair (rightLL) is null then nothing to do , the leftPair along with new node is the final LL
    // else if rightPair have some node then add it to the end of (leftLL + Current node) and leftpair's tail would point to end of right pair
    if (rightPair.first != nullptr) {
        leftPair.second->next = rightPair.first;
        leftPair.second = rightPair.second;
    }

    return leftPair;
} 

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	return constructLinkedListHelper(root).first;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}
