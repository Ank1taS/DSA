// You have been given a singly linked list of integers along with an integer 'N'. 
// Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

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
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// to get length of LinkedList
int length(Node *head)
{
    int count {0};
    Node *temp {head};
    
    while (temp != NULL) {
        ++count;
        temp = temp -> next;
    }
    
    return count;
}

// append last n to first()
Node *appendLastNToFirst(Node *head, int n) {
	if (head && n) {			// (head != NULL && n != 0)
		int index = length(head) - n;

		Node *currentNode = head;

		for (int i = 1; i < index; ++i) {
			currentNode = currentNode->next;
		}

		Node *newHead = currentNode->next;
		currentNode->next = NULL;
		currentNode = newHead;

		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		} 

		currentNode->next = head;

		head = newHead;
	}

	return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}