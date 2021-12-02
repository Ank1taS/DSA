// For a given singly linked list of integers, find and return the node present at the middle of the list.
// If the length of the singly linked list is even, then return the first middle node.



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

// to get mid point of LL
Node *midPoint(Node *head) {
	// if no node is there then return as it is
	if (!head) {
        return head;
    }
	
    Node *slow = head;
    Node *fast = head->next;

	// Fast pointer will move ahead two pointers at a time, while the slower one will move at a speed of a pointer at a time.​ 
	// In this way, when the fast pointer will reach the end, by that time the slow pointer will be at the middle position of the array.
	// as fast is peoceeded by 2 nodes we need to check fast and fast->next is null or not
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		Node *mid = midPoint(head);
		if (mid != NULL)
		{
			cout << mid->data;
		}
		cout << endl;
	}
	return 0;
}
