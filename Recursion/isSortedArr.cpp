// check an array is sorted or not (increasing order)

#include<iostream>
using namespace std;

bool isSorted(int *arr, int size) {
    // base case
    // if there is 0 or 1 elements then they considered to be sorted by themselves
    if (size <= 1) {
        return true;
    }

    // small calculation
    if (arr[0] > arr[1]) {
        return false;
    }

    return isSorted(arr + 1, size - 1);
}

int main() {
    int size;
    cin >> size;

    // create dynamic array
    int *arr = new int[size];

    for (int i {0}; i < size; ++i) {
        cin >> arr[i];
    }

    cout << (isSorted(arr, size) ? "true" : "false");
    

    return 0;
}