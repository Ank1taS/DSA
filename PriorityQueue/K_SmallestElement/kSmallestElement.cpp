// K smallest Elements

// You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
// Note: Order of elements in the output is not important.

// Time complexity  -  O(n * logk)
// space complexity - O(k).


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> kSmallest(int arr[], int size, int k) {
    // crate a priority queue
    priority_queue<int> pq;

    // insert 1st k elemnt of array in pq
    for (int i {0}; i < k; ++i) {
        pq.push(arr[i]);
    }

    // from next index onward ie K index, if element(onward) is smaller than the max element of pq then replce it with the new element else proceed
    int newIndex {k}; 

    while (newIndex < size) {
        if (arr[newIndex] < pq.top()) {
            pq.pop();                   // remove current max element from the heap
            pq.push(arr[newIndex]);     // insert the new smaller element in the queue
        }

        ++newIndex;
    }

    // copy element of pq to vector
    vector<int> vec;
    while (pq.empty() == false) {
        vec.push_back(pq.top());
        pq.pop();
    }

    return vec;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
    return 0;
}

