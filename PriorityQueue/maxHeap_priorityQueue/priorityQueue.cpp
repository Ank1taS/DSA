// priority queue - max heap implementation

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

public:
    // Implement the constructor here
    PriorityQueue() {

    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);

        int childIndex {pq.size() - 1};

        while (childIndex > 0) {
            int parentIndex {(childIndex - 1) / 2};

            if (pq.at(childIndex) > pq.at(parentIndex)) {
                int temp {pq.at(childIndex)};
                pq.at(childIndex) = pq.at(parentIndex);
                pq.at(parentIndex) = temp;

                childIndex = parentIndex;
            }
            else {
                break;
            }
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if (pq.size() == 0) {
            return INT_MIN;
        }

        return pq.at(0);
    }

    int removeMax() {
        // Implement the removeMax() function here
        if (pq.size() == 0) {
            return INT_MIN;
        }

        int result {pq.at(0)};
        pq.at(0) = pq.at(pq.size() - 1);
        pq.pop_back();

        int parentIndex {0};
        int leftChildIndex {1};
        int rightChildIndex {2};
        
        while (leftChildIndex < pq.size()) {
            int maxIndex {leftChildIndex};

            if (rightChildIndex < pq.size() && pq.at(rightChildIndex) > pq.at(leftChildIndex)) {
                maxIndex = rightChildIndex;
            }

            if (pq.at(parentIndex) < pq.at(maxIndex)) {
                int temp {pq.at(parentIndex)};
                pq.at(parentIndex) = pq.at(maxIndex);
                pq.at(maxIndex) = temp;

                parentIndex = maxIndex;
                leftChildIndex = (2 * parentIndex) + 1;
                rightChildIndex = (2 * parentIndex) + 2;
            }
            else {
                break;
            }
        }

        return result;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}