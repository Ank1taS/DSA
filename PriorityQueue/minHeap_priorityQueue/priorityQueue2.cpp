// priority queue - min heap implementation
// CN solution

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
    if(isEmpty()) {
			return 0;		// Priority Queue is empty
		}
		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		// down-heapify

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;
	
		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;
		
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}

		return ans;

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