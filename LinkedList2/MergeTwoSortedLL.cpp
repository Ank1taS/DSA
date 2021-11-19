// Merge Two Sorted LL

// You have been given two sorted(in ascending order) singly linked lists of integers.
// Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.



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

// To merge 2 sorted LL
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
    if (!head1 || !head2) {
        return head1;
    }

    Node *finalHead = NULL;
    Node *finalTail = NULL;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            if (!finalHead ) {
                finalHead = head1;
                finalTail = head1;
            }
            else {
                finalTail->next = head1;
                finalTail = head1;
            }

            head1 = head1->next;
        }
        else {
            if (!finalHead ) {
                finalHead = head2;
                finalTail = head2;
            }
            else {
                finalTail->next = head2;
                finalTail = head2;
            }

            head2 = head2->next;
        }
    }

    if (head1) {
        finalTail->next = head1;
    }
    else {
        finalTail->next = head2;
    }

    return finalHead;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}