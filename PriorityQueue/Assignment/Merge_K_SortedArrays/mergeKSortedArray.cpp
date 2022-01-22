// Merge K sorted arrays

// Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
// Hint : Use Heaps.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Triplet {
public:
    int element;        // stores values present in vector   
    int elementIndex;   // stores index of the element present in vector
    int vectorIndex;    // stores vector number to track which vector element is pushed in sorted vector

    Triplet(int element, int elementIndex, int vectorIndex) 
    : element{element}, elementIndex {elementIndex}, vectorIndex {vectorIndex} {}
};


class Comp {
    public:
    bool operator() (Triplet a, Triplet b) {
        return a.element > b.element;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    // resultant sorted vector
    vector<int> sortedResult;

    // min-priority queue 
    // it stores k elements and from which min element is shift to sort vector
    priority_queue<Triplet, vector<Triplet>, Comp> pq;

    for(int i {0}; i < input.size(); ++i) {
        Triplet obj (input.at(i)->at(0), 0, i);
        pq.push(obj);
    } 

    int sortIndex {0};
    while (pq.empty() == false) {
        Triplet temp (pq.top());
        sortedResult.push_back(temp.element);
        pq.pop();

        if (temp.elementIndex + 1 < input.at(temp.vectorIndex)->size()) {
            Triplet obj(input.at(temp.vectorIndex)->at(temp.elementIndex + 1), temp.elementIndex + 1, temp.vectorIndex);
            pq.push(obj);
		}

    }
    return sortedResult;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
