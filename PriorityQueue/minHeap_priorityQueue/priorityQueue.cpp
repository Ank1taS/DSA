// priority queue - min heap implementation

#include <iostream>
#include <climits>
#include <vector>
using namespace std;


// priority queue (min heap) class
class PriorityQueue {
    vector<int> pqVec;

public:
    // checks Priority queue (vector) is empty or not
    void isEmpty() {
        return pqVec.size() == 0;
    }

    // returns size of Priority queue (vector) pqVec
    int getSize() {
        return pqVec.size();
    }

    // returns min element os the Priority queue (vector)
    int getMin() {
        if (pqVec.size() == 0) {
            return 0;
        }
        return pqVec.at(0);
    } 

    // insert element in priority queue
    void insert(int data) {
        pqVec.push_back(data);

        int childIndex {pqVec.size() - 1};

        while (childIndex > 0) {
            int parentIndex {(childIndex - 1) / 2};

            if (pqVec.at(parentIndex) > pqVec.at(childIndex)) {
                int temp {pqVec.at(parentIndex)};
                pqVec.at(parentIndex) = pqVec.at(childIndex);
                pqVec.at(childIndex) = temp;

                childIndex = parentIndex;
            }
            else {
                break;
            }
        }
    }

    // to remove min element from the priorityQueue
    int removeMin() {
        if (pqVec.size() == 0) {
            return -1;      // mark as queue is empty
        }

        int result {pqVec.at(0)}; 
        pqVec.at(0) = pqVec.at(pqVec.size() - 1);
        pqVec.pop_back();

        int currentIndex {0};
        int leftChildIndex {1};
        int rightChildIndex {2};

        while (leftChildIndex < pqVec.size()) {
            int minIndex {leftChildIndex};

            if (rightChildIndex < pqVec.size() && pqVec.at(leftChildIndex) > pqVec.at(rightChildIndex)) {
                minIndex = rightChildIndex;
            }
            
            if (pqVec.at(currentIndex) > pqVec.at(minIndex)) {
                int temp {pqVec.at(currentIndex)};
                pqVec.at(currentIndex) = pqVec.at(minIndex);
                pqVec.at(minIndex) = temp;

                currentIndex = minIndex;
                leftChildIndex = (2 * currentIndex) + 1;
                rightChildIndex = (2 * currentIndex) + 2;
            }
            else { 
                break;
            }
        }
        return result;
    }
}




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
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMin
                cout << pq.removeMin() << "\n";
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

    return 0;
}