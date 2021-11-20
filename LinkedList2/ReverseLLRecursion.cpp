// Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. 
// You have to do this in O(N) time complexity where N is the size of the linked list.


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


Node *reverseLinkedListRec(Node *head) {
    if (!head || !(head->next)) {
        return head;
    }

    Node *smallLL = reverseLinkedListRec(head->next);

    head->next->next = head;    // Node *tail = head;   tail->next = head
    head->next = NULL;

    return smallLL;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
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

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}
