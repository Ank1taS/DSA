// Given a singly linked list of integers, sort it using 'Bubble Sort.' itteratively


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

int getLength(Node * head) {
    int count {0};

    while (head) {
        ++count;
        head = head->next;
    }
    return count;
}

Node *bubbleSort(Node *head) {
	if (!head || !head->next) {
        return head;
    }

    int length {getLength(head)};
    bool flag;

    for (int i = 0; i < length - 1; ++i) {
        
        Node *prev = NULL;
        Node *current = head;
        Node *future = current->next;
        
        for (int j {0}; j < length - i - 1; ++j) {
            if (current->data > future->data) {
                if (!prev) {
                    current->next = future->next;
                    future->next = current;

                    head = future;
                    prev = head;
                }
                else {
                    prev->next = current->next;
                    current->next = future->next;
                    future->next = current;
                    
                prev = current;
                }

                flag = true;
            }
            else {
                prev = current;
                
            current = current->next;
            future = future->next;
            
            }
            
        }
        if (!flag) {
            return head;
        }
    }
    return head;
}


int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}