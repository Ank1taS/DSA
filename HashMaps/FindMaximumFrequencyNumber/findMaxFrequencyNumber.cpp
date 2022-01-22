// Code : Maximum Frequency Number

// You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
// If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

// using hashmap


#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int highestFrequency(int arr[], int n) {
    unordered_map<int, int> frequencyMap;
    // to store the max frequency
    int maxFrequency {0};

    // insert element and curresponding frequency
    for (int i {0}; i < n; ++i) {
        // if (frequencyMap.count(arr[i]) > 0) {
        //     ++frequencyMap.at(arr[i]);
        // }
        // else {
        //     frequencyMap[arr[i]] = 1;
        // }

        frequencyMap[arr[i]]++;

        maxFrequency = max (maxFrequency, frequencyMap.at(arr[i]));
    }
    

    for (int i {0}; i < n; ++i) {
        if (maxFrequency == frequencyMap.at(arr[i])) {
            return arr[i];
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;

    return 0;
}
