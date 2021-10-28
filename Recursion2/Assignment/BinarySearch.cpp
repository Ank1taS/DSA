// Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. 
// Return the index of x.
// Return -1 if x is not present in the given array.
// Note : If given array size is even, take first mid.

#include <iostream>
// #include "solution.h"
using namespace std;

int helper(int input[], int startIndex, int endIndex, int element) {
    if (endIndex < startIndex) {
        return -1;
    }

    int minIndex = (startIndex + endIndex) / 2;

    if (element == input[minIndex]) {
        return minIndex;
    }
    else if (element < input[minIndex]) {
        return helper(input, startIndex, minIndex - 1, element);
    }
    else {
        return helper(input, minIndex + 1, endIndex, element);
    }
}

int binarySearch(int input[], int size, int element) {
    return helper(input, 0, size - 1, element);
}

int main() {
    int input[100000], length, element, ans;
    
    cin >> length;

    for(int i =0;i<length;i++) { 
        cin >> input[i];;
    }

    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;

    return 0;
}
