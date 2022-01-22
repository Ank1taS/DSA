// Code : Pair Sum to 0
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
// Note: Array A can contain duplicate elements as well.


#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n) {
    // to store total numbers of pairs
	int pairCount {0};
    // maps to store each element and their frequency
    unordered_map<int, int> mp;

    // 
    for(int i {0}; i < n; ++i) {
        // searchKey stores coressponding value that sum will be 0
        int searchKey {-1 * arr[i]};

        // if search value is there in map
        if (mp.count(searchKey) > 0) {
            // paircount will be increase to corresponding value of that key
            // ex if -2 is search value and 2 is key having 3 frequncy then 3 pairs will be created so totalpair will be incresed by 3
            pairCount += mp.at(searchKey);
        }

        // frequncy of a element is incresed by 1 ie if new element then 1 else frequncy incresed by 1
        mp[arr[i]]++;
    }
    // return total pairs count
    return pairCount;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
