// Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> vec;

    if (!root) {
        // vec.push_back(nullptr);
        return vec;
    }

    // linkedlist head nad tail node to track each level node's data
    Node<int> *head {nullptr};
    Node<int> *tail {nullptr};

    // queue to store each level nodes of binary tree followed by nullptr
    queue<BinaryTreeNode<int>*> pendingNode;
    // initially it stores root node followed by nullptr as mark of end of 1st level
    pendingNode.push(root);
    pendingNode.push(nullptr);

    while (pendingNode.size()) {
        // store front elemnt of queqe in currentNode
        BinaryTreeNode<int> *currentNode {pendingNode.front()};

        // if current node is nullptr it marks end of a level
        if (currentNode == nullptr) {
            // push the head of linklist that have nodes of current level
            vec.push_back(head);
            // from next data (after nullptr) is a new level. so a new Linklist will be created so head an d tail should point to nullptr
            head = nullptr;
            tail = nullptr;

            // if there is still elements after the currentNode nullptr that means it is not the end of queue 
            // then print newline then push a nullptr to the end of queue
            if (pendingNode.size() != 1) {
                pendingNode.push(nullptr);
            } 
        }
        else {      // if it is not nullptr then it is a tree node
            
            // create a node dynamically to store currentNode->data
            Node<int> *newNode = new Node<int>(currentNode->data);

            // if head and tail points to nullptr that mean linkedList is empty. then both head and tail will point to same node
            if (!head || !tail) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }

            // push it's left child if exists
            if (currentNode->left) {
                pendingNode.push(currentNode->left);
            }
            // push it's right child if exists
            if (currentNode->right) {
                pendingNode.push(currentNode->right);
            }
        }
        pendingNode.pop();
    }
    return vec;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }

    return 0;
}
