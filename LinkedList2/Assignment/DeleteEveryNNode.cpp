// You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' 
// Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
// To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.



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

Node *skipMdeleteN(Node *head, int M, int N) {
	// when LL is NULL return NULL ie empty LL or M is 0, delete all nodes which results a empty LL.
	if (!head || !M) {
        return nullptr;
    }

	// when N = 0, No Node will be remove so return LL as it is. 
	if (!N) {
		return head;
	}

    Node *current = head;

    while (current) {
		// proceed current node M - 1 times
        for (int countm = 1; countm < M && current->next != NULL; ++countm) {
            current = current->next;
        }

		// delete next n nodes from the current node
        for (int countn = 0; countn < N && current->next != NULL; ++countn) {
            Node *temp = current->next;
            current->next = temp->next;

            delete temp;
        }
        
		// after deletion of n node proceed current node by 1 nodes
	    current = current->next;    
    }
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
