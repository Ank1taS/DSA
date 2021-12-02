// Given a singly linked list of integers, sort it using 'Merge Sort.'

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

// to get mid node
Node *midPoint(Node *head) {
	if (!head) {
        return head;
    }
	
    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// to merge 2 sorted LL
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
    if (!head2) {
        return head1;
    }
    if (!head1) {
        return head2;
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

// mergeSort 
Node* mergeSort(Node *head) {
    if (!head || !(head->next)) {
        return head;
    }

    Node *midNode = midPoint(head);
    Node *leftHead = head;
    Node *rightHead = midNode->next;
    midNode->next = NULL;
    
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);

    leftHead = mergeTwoSortedLinkedLists(leftHead, rightHead);

    return leftHead;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}