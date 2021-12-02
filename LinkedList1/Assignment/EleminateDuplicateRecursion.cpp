// Eliminate duplicates from LL - recursivelly

// You have been given a singly linked list of integers where the elements are sorted in ascending order. 
// Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.


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

// 
Node *removeDuplicates(Node *head) {
	// if LL have no or single element return as it is
	if (!head || !(head->next)) {
		return head;
	}

	Node *currentNode = head->next;

	// if data of currentNode is same as head of data we will remove the current node 
	while (currentNode->data == head->data) {
		// if next node of head node it current node is not the last node, then algorithm to remove a intermidiate node 
		if (currentNode->next){
			Node *temp = currentNode;
			currentNode = currentNode->next;
			head->next = currentNode;
			delete temp;
		}
		// if next node of head node it current node is the last node then store null at net of head to terminate the LL and delete current or last node of LL
		else {
			head->next = NULL;
			delete currentNode;
		}
	}

	Node *newNode = removeDuplicates(head->next);

	return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}