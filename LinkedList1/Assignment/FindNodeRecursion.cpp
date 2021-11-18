// You have been given a singly linked list of integers. 
// Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.
// Note    :  Assume that the Indexing for the singly linked list always starts from 0.


#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

// find node()
int findNode(Node *head, int n){
    if (! head) {
        return -1;
    }

    if (head->data == n) {
        return 0;
    }

    int index = findNode(head->next, n);

    if (index == -1) {
        return -1;
    }
    else {
        return index + 1;
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}