// Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.


#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    //mp key - sum till ith index, and value stores index number
    unordered_map<int, int> mp;

    // key stores sum of consecutive elements
    int key {0}; 
    // tracks max length of index whose sum is 0
    int maxLength {0};
    
    // 
    for (int i {0}; i < n; ++i) {
        key += arr[i];

        // if sum till ith index is 0 then compare if current index distance from beging is greater than maxLength
        // if true then set maxLength to i+1
        if (key == 0) {
            if (maxLength < i + 1) {
                maxLength = i + 1;
            }
        }

        // if key element is already present in map that means the sum of elements from the index of key to current index is 0 
        if (mp.count(key) > 0) {
            // store the distance between key's value ie previous index and current index
            int currentLength {i - mp[key]};

            // if current length is greater then max length then set maxLength to current length
            if (maxLength < currentLength) {
                maxLength = currentLength;
            }
        } 
        // if key element is not present in map then store it with current index ie i to track sum till ith index
        else {
            mp[key] = i;
        }
    }

    // return maxLength that stores max distance with sum 0 
    return maxLength;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}