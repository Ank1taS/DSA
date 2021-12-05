

class Node {
    public:
        int data;
    	Node *prev;
    	Node *next;
    	Node(int data) {
            this->data = data;
            next = prev = nullptr;
        }
};

class Deque {
    // Complete this class
    Node *head;
    Node *tail;
    int size;
    int capacity;
    
    public:
    	Deque(int size) : size {0}, capacity {10}, head {nullptr}, tail {nullptr} {}
    	
    	void insertFront(int element) {
            if (size == capacity) {
                cout << -1 << endl;
                return;
            }
            
            Node *newNode {new Node(element)};
            
            if (!head) {
                head = tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            
            ++size;
        }
    
    	void insertRear(int element) {
            if (size == capacity) {
                cout << -1 << endl;
                return;
            }
            
            Node *newNode {new Node(element)};
            
            if (!tail) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            
            ++size;
        }
    
    	void deleteFront() {
			if (!head) {
                cout << -1 << endl;
                
                return;
            }
            
            Node *temp {head};
            head = head->next;
            
            if (!head) {
                tail = nullptr;
            }
            else {
            	head->prev = nullptr;                
            }
            
            delete temp;
            --size;
        }
    
    	void deleteRear() {
            if (!tail) {
                cout << -1 << endl;
                return;
            }
            
            Node *temp {tail};
            tail = tail->prev;
            
            if (!tail) {
                head = nullptr;
            }
            else {
                tail->next = nullptr;
            }
            
            delete temp;
            --size;
        }
    
    	int getFront() const {
            if (!head) {
                return -1;
            }
            
            return head->data;
        }
    
    	int getRear() const {
            if (!tail) {
                return -1;
            }
            
            return tail->data;
        }
    
};

