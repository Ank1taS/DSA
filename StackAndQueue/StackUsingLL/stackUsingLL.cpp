#include <iostream>
using namespace std;

template <typename T>
class Node {
public:

    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
	// Define the data members
    Node<T> *head;
    int totalNodeCount;

public:
	/*----------------- Public Functions of Stack -----------------*/
    Stack() ;
    int getSize() const;
    bool isEmpty() const;
    void push(T element);
    T pop();
    T top() const;
};

// Implement the Constructor
template <typename T>
Stack<T>::Stack() {
    head = NULL;
    totalNodeCount = 0;
}

// Implement the getSize() function
template <typename T>
int Stack<T>::getSize() const {
    return totalNodeCount;
}

// Implement the isEmpty() function
template <typename T>
bool Stack<T>::isEmpty() const{
        
    return head == NULL;    // totalNodeCount == 0;
}

// Implement the push() function
template <typename T>
void Stack<T>::push(T element) {
        ++totalNodeCount;

        Node<T> *newNode = new Node<T>(element);

        newNode->next = head;
        head = newNode;
}

// Implement the pop() function
template <typename T>
T Stack<T>::pop() {
        if (!head) {
            return -1;
        }
        
        --totalNodeCount;
        T element = head->data;
        Node<T> *temp {head};
        head = head->next;
        delete temp;
    
        return element;
}

// Implement the top() function
template <typename T>
T Stack<T>::top() const{
        if (!head) {
            return -1;
        }

        return head->data;
}

int main() {
    Stack<int> st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}