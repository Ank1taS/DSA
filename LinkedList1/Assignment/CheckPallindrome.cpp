// You have been given a head to a singly linked list of integers. 
// Write a function check to whether the list given is a 'Palindrome' or not.


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

void print(Node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// length of LL
int lengthLL(Node *head)
{
    int count {0};
    
    while (head != NULL) {
        ++count;
        head = head -> next;
    }
    
    return count;
}

// reverse the Linked List
Node* reverseLL(Node *head) {
    Node *temp = head;
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = temp;

    while (current) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    temp = prev;

    return temp;
}

bool isPalindrome(Node *head) {
    int length = lengthLL(head);
    Node *revHead = head;

    for (int i = 0; i < length / 2; ++i) {
        revHead = revHead->next;
    }
    revHead = reverseLL(revHead);

    // print(head);
    // print(revHead);

    while (head && revHead) {
        if (head->data == revHead->data) {
            head = head->next;
            revHead = revHead->next;
        }
        else {
            return false;
        }
    }  
    return true;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}
