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
	// no swap operation can be perform when LL is empty or contain 1 element or i and j have same node. 
	// so return LL as it is
	if (!head || !(head->next) || i == j) {
        return head;
    }

    Node *currenti {head};
    Node *previ {nullptr};
    Node *currentj {head};
    Node *prevj {nullptr};

	// previ will point previous node of ith node and currenti will point ith node 
    for (int count = 0; count < i && currenti; ++count) {
        previ = currenti;
        currenti = currenti->next;
    }

	// prevj will point previous node of jth node and currentj will point jth node 
    for (int count = 0; count < j && currentj; ++count) {
        prevj = currentj;
        currentj = currentj->next;
    }

	//if any of currenti or currentj will be NULL, it indicates i or j node respectively not present in LL. In that case LL will be return as it is
    if (!currenti || !currentj) {
        return head;
    }

	// if previ is not NULL that mean i is a intermidiate node
    if (previ) {
        previ->next = currentj;
    }
	// if previ is  NULL that mean i is the head node
    else {
        head = currentj;
    }

	// if prevj is not NULL that mean j is a intermidiate node
    if (prevj) {
        prevj->next = currenti;
    }
	// if prevj is  NULL that mean j is the head node
    else {
        head = currenti;
    }

	// swap 2 nodes by exchanging their next nodes
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
