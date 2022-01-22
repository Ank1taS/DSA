// Running Median
// You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
// Print only the integer part of the median.

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

void findMedian(int *arr, int n) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    // for each element in the data stream
    for (int i {0}; i < n; ++i) {
        if (maxHeap.size() && arr[i] > maxHeap.top()) {
            minHeap.push(arr[i]);
        }
        else {
            maxHeap.push(arr[i]);
        }

        if (abs(maxHeap.size() - minHeap.size()) > 1) {
            if (maxHeap.size() > minHeap.size()) {
                int temp {maxHeap.top()};
                maxHeap.pop();
                minHeap.push(temp);
            }
            else {
                int temp {minHeap.top()};
                minHeap.pop();
                maxHeap.push(temp);
            }
        }

        int median;
        int totalSize {maxHeap.size() + minHeap.size()};

        // when numbers of elements are odd
        if (totalSize % 2 == 1) {
            if (maxHeap.size() > minHeap.size()) {
                median = maxHeap.top();
            }
            else {
                median = minHeap.top();
            }
        }
        // when numbers of elements is even
        else {
            median = 0;
            
            if (maxHeap.empty() == false) {
                median += maxHeap.top();
            }
            if (minHeap.empty() == false) {
                median += minHeap.top();
            }

            median /= 2;
        }
        cout << median << " ";
    } 
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}

