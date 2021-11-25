// Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
//  'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.

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

class NodePair {
public:
    Node *head;
    Node *tail;

    NodePair(Node *head, Node *tail) 
        : head {head}, tail {tail} {}
};

NodePair reverse (Node *head, Node *tail) {
    Node *prev = head;
    Node *current = head->next;
    Node *next = NULL;

    while (current != tail->next || current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    NodePair* obj(prev, head);

    return obj;
}

Node *kReverse(Node *head, int k) {
	if (!head || !head->next) {
		return head;
	}
	Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *current = head;

    while (current) {
        head1 = current;
        
        for (int i {0}; i < k; ++i) {
            current = current->next;
        }
    }

    tail1 = current;
    head2 = current->next;

    NodePair *obj = reverse(head1, tail1);

    head1 = obj->head;
    tail1 = obj->tail;        
	tail1->next = head2;

	head2 = kReverse(head2);

	return head1;
}

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


int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}