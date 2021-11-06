// You have been given a random integer array/list(ARR) of size N. 
// Write a function that rotates the given array/list by D elements(towards the left).
// 
// Note:
// Change in the input array/list itself. You don't need to return or print the elements.

// by reversing element approch 

#include <iostream>
using namespace std;

void rotate(int *input, int d, int n) {

	// reverse entire array
    for (int i = 0; i < n / 2; ++i) {
        int temp = input[i];
        input[i] = input[n - i - 1];
        input[n - i - 1] = temp;        
    } 

	// reverse first [n - d] part of array
    for (int i = 0; i < (n - d) / 2; ++i) {
        int temp = input[i];
        input[i] = input[n - d - i - 1];
        input[n - d - i - 1] = temp;
    } 

	// reverse last [d] elements of array
    for (int i = n - d, j = n - 1 ; i < j; ++i, --j) {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
