// Given a singly linked list of integers and position 'i', 
// delete the node present at the 'i-th' position in the linked list recursively.


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

// delete node
Node* deleteNodeRec(Node *head, int position) {
    if (! head) {
        return head;
    }

    if (position == 0) {
        Node *temp = head;
        head = head->next;

        delete temp;
        return head;
    }

    Node *newHead = deleteNodeRec(head->next, position - 1);

    head->next = newHead;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNodeRec(head, pos);
		print(head);
	}

	return 0;
}

