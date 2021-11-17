// simple linked list program

#include<iostream>

class Node {
public:
    int data;
    Node *next;

    // constructor
    Node(int data) : data{data} {
        next = NULL;
    }

};

void print(Node *head) {
    while( head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }

    std::cout << std::endl;
}

int main() {
    // dynamically
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Node *head = n1;
    print(head);

    return 0;
}
