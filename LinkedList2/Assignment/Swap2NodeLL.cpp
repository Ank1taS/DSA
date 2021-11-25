// You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.


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

Node *swapNodes(Node *head, int i, int j)
{
	if (!head || !(head->next)) {
        return head;
    }

    if (i == j) {
        return head;
    }

    Node *currenti = head;
    Node *previ = NULL;
    Node *currentj = head;
    Node *prevj = NULL;

    for (int count = 0; count < i && currenti; ++count) {
        previ = currenti;
        currenti = currenti->next;
    }

    for (int count = 0; count < j && currentj; ++count) {
        prevj = currentj;
        currentj = currentj->next;
    }

    if (!currenti || !currentj) {
        return head;
    }

    if (previ) {
        previ->next = currentj;
    }
    else {
        head = currentj;
    }

    if (prevj) {
        prevj->next = currenti;
    }
    else {
        head = currenti;
    }

    Node *temp = currentj->next;
    currentj->next = currenti->next;
    currenti->next = temp;

    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
