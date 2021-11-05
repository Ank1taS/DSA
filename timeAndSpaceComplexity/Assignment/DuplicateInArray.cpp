// You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). 
// Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. 
// find and return that duplicate number present in the array.
// Note :
// Duplicate number is always present in the given array/list.

// Time complexity  - O(n)
// Space complexity - O(1)


#include <iostream>
using namespace std;

// #include "solution.h"

int findDuplicate(int *arr, int n) {
    int sumArr {0};

    // sum array
    for (int i = 0; i < n ; ++i) {
        sumArr += arr[i];
    }

    // sum of 1st n digit 
    int sumNum = ((n - 2) * (n - 1)) / 2;

    return sumArr - sumNum;
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}
