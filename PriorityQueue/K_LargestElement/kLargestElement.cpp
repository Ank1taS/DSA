// Code : K largest elements

// You are given with an integer k and an array of integers that contain numbers in random order.
//  Write a program to find k largest numbers from given array. You need to save them in an array and return it.

// Time complexity  - O(nlogk) 
// space complexity - O(k)


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> kLargest(int input[], int size, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    // insert 1st k elemnt of array in pq
    for (int i {0}; i < k; ++i) {
        pq.push(arr[i]);
    }

    // from next index onward ie K index, if element(onward) is smaller than the max element of pq then replce it with the new element else proceed
    int newIndex {k}; 

    while (newIndex < size) {
        if (arr[newIndex] > pq.top()) {
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
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
	
	return 0;
}

