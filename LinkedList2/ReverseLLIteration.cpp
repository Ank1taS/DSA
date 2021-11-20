// Given a singly linked list of integers, reverse it iteratively and return the head to the modified list.


#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverseLinkedList(Node *head) {
    // if (!head || !(head->next)) {
    //     return head;
    // }

    Node *prev = NULL;
    Node *next = NULL;
    Node *current = head;

    while (current) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;        
    }

    head = prev;

    return head;    
}

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}