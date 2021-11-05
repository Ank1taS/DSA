// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
// You need to find and return that number which is unique in the array/list.

// time complexity  - O(N)
// space complexity - O(1)
#include <iostream>
using namespace std;

// #include "solution.h"

int findUnique(int *arr, int n) {
    int uniqueNum {0};

    for (int i = 0; i < n; ++i) {
        uniqueNum = uniqueNum ^ arr[i];         // doing XOR operation
    }

    return uniqueNum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}

//     1 1 0
// ^   0 1 1
// -------------
//     1 0 1