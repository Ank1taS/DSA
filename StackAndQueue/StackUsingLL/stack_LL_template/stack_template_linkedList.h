template<typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;

    Node(T data);
};

template<typename T>
class Stack {
    Node<T>* head;
    int size;

public:
    // constuctor
    Stack();
    ~Stack();

    // push
    void push(const T data);

    // pop
    T pop();

    // top
    T top() const;

    // size
    int getSize() const;

    // is empty
    bool isEmpty() const;

};

