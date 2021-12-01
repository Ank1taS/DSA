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
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int totalNodeCount;
    
public:
    Queue();

    // getSize() function to return size
    int getSize();

    // isEmpty() to return true if queue is empty
    bool isEmpty();

    // to insert a new element to queue
    void enqueue(T);

    // to deleteand return a node or element from queue
    T dequeue();

    // to return the front element
    T front();
};

template<typename T>
Queue<T>::Queue()  : head{NULL}, tail {NULL}, totalNodeCount{0} {}

template<typename T>
int Queue<T>::getSize() {
    return totalNodeCount;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return totalNodeCount == 0;
}

template<typename T> 
void Queue<T>::enqueue(T element) {
    Node<T> *newNode = new Node<T>(element);
    ++totalNodeCount;
    
    if (!head) {
        head = newNode;
        tail = newNode;

        return;
    }

    tail->next = newNode;
    tail = tail->next;
}

template<typename T> 
T Queue<T>::dequeue() {
    if (!head) {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    --totalNodeCount;
    T element = head->data;
    Node<T> *temp = head;

    head = head->next;
    delete temp;
    
    // if head is null that mean last node of ll is now deleted so tail must not point to that last node after it
    if (!head) {
        tail = NULL;
    }

    return element;
}

template<typename T> 
T Queue<T>::front() {
    if (!head) {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    return head->data;
}

int main() {
    Queue<int> q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}