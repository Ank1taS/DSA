// Given a singly linked list of integers and an integer n, 
// find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) : data {data}, next {NULL} {}
};

Node* takeinput() {
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1) {
        Node *newNode(data);

        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }

    return head;
}

int findNodeRec(Node *head, int n) {
	if (!head) {
        return -1;
    }

    if (head->data == n) {
        return 0;
    }

    int index = findNodeRec(head->next, n);

    if (index == -1) {
        return -1;
    }
    else {
        return index + 1;
    }
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
	}
}
