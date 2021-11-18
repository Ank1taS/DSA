// delete a specific node


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

Node* takeinput() {
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1) {
        Node *newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;

        }
        cin >> data;
    }
    return head;
    // int data;
	// cin >> data;
	// Node *head = NULL, *tail = NULL;
	// while (data != -1)
	// {
	// 	Node *newNode = new Node(data);
	// 	if (head == NULL)
	// 	{
	// 		head = newNode;
	// 		tail = newNode;
	// 	}
	// 	else
	// 	{
	// 		tail->next = newNode;
	// 		tail = newNode;
	// 	}
	// 	cin >> data;
	// }
	// return head;
}

// delete node
Node* deleteNode(Node *head, int position) {
    if (!head || !head->next) {
        return head;
    } 
    Node *currentNode = head;
    int count {0};

    if (position == 0) {
        Node *temp = head;
        head = head->next;

        delete temp;
        return head;
    } 

    while(currentNode->next != NULL && count < position - 1) {
        currentNode = currentNode->next;
        ++count;
    }

    if (currentNode->next != NULL) {
        Node *temp = currentNode->next;

        currentNode->next = temp->next;
        delete temp;
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
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}