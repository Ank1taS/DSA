// Kth largest element

// Given an array A of random integers and an integer k, find and return the kth largest element in the array.
// Note: Try to do this question in less than O(N * logN) time.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(int* arr, int size, int k) {
    // create a priority queue(min) 
    priority_queue<int, vector<int>, greater<int>> pq;

    // insert 1st k elements of array into pq
    for (int i {0}; i < k; ++i) {
        pq.push(arr[i]);
    } 

    // from next index onward ie K index, if element(onward) is greater than the min element of pq then replce it with the new element else proceed
    for (int i {k}; i < size; ++i) {
        if (pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // kth max element is the min element of pq
    return pq.top(); 

}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}