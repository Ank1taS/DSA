// Check Max-Heap
// Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.


#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    int currentIndex {0};
    int leftChildIndex {1};
    int rightChildIndex {2};

    while (leftChildIndex < n || rightChildIndex < n) {
        if (leftChildIndex < n && arr[currentIndex] < arr[leftChildIndex]) {
            return false;
        } 
        else if (rightChildIndex < n && arr[currentIndex] < arr[rightChildIndex]) {
            return false;
        }

        ++currentIndex;
        leftChildIndex = (2 * currentIndex) + 1;
        rightChildIndex = (2 * currentIndex) + 2;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}