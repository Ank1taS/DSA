// For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. 
// The relative order of the odd and even terms should remain unchanged.


#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput() {
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

void print(Node *head) {
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// to store even Node after Odd nodes
Node* evenAfterOdd(Node *head) {
    if (!head || !(head->next)) {
        return head;
    }

    Node *evenHead = NULL;
    Node *evenTail = NULL;
    Node *oddHead = NULL;
    Node *oddTail = NULL;
    Node *current = head;

    while(current) {
        if (current->data % 2 == 0) {
            if (!evenHead) {
                evenHead = current;
                evenTail = current; 
            }
            else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        else {
            if (!oddHead) {
                oddHead = current;
                oddTail = current;
            }
            else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }

        current = current->next;
    }
    if(evenHead && oddHead) {
        oddTail->next = evenHead;
        evenTail->next = NULL;
        return oddHead;
    }
    else if (!evenHead) {
        return oddHead;
    }
    else {
        return evenHead;
    }
}

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}
