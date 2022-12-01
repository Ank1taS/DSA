#include "stack_template_linkedList.h"

template<typename T>
Node<T>::Node(T data)
    : data {data}, nextNode {nullptr} {}
    

template<typename T>
Stack<T>::Stack() {
    this->head = nullptr;
    this->size = 0;
}

template <class T>
Stack<T>::~Stack() {
    while (head != nullptr) {
        Node<T> *temp = head;
        head = head->nextNode;
        delete temp;
    }
}

template<typename T>
int Stack<T>::getSize() const {
    return this->size;
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return this->size == 0;
}

template<typename T>
void Stack<T>::push(const T data) {
    Node<T> *newNode {new Node<T>(data)};

    if (head == nullptr) {
        head = newNode;
    }
    else {
        // Node<T>* temp {head};
        newNode->nextNode = head;
        head = newNode;
    }
    // update size
    ++size;
}

template<typename T>
T Stack<T>::pop() {
    if (head == nullptr) {
        return 0;
    }

    T ans {head->data};

    Node<T>* temp {head};
    head = head->nextNode;
    delete temp;
    --size;

    return ans;
}

template<typename T>
T Stack<T>::top() const {
    if (head == nullptr) {
        return 0;
    }

    return head->data;
}

template class Stack<int>;
template class Stack<char>;
template class Stack<float>;
template class Stack<double>;
