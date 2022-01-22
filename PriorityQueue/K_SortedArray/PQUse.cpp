#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int input[], int n, int k) {
	priority_queue<int> pq;

	// insert 1st k elements of array in pq
	for(int i {0}; i < k; i++) {
		pq.push(input[i]);
	}

	// to track index of array where sort element needs to be
	int j {0};
	
	for(int i {k}; i < n; i++) {
		// store max element of pq at jth index 
		input[j] = pq.top();
		// remove max element from pq as it is already placed at its appropiate position in array
		pq.pop();
		// insert next element of pq is inserted in pq
		pq.push(input[i]);
		// target index increase
		++j;
	}

	// sort oparation over the last k element of array which are remained in pq
	while(!pq.empty()) {
		input[j] = pq.top();
		pq.pop();
    	++j;
	}

}
	
int main() {
	int input[] = {10, 12, 6, 7, 9};
	int k = 3;
	kSortedArray(input, 5, k);
	for(int i = 0; i < 5; i++) {
		cout << input[i] << " ";
	}
}

