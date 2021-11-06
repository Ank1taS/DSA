// You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. 
// You need to store and print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, 
// when there is a common value that exists in both the arrays/lists.

// Note :
// Input arrays/lists can contain duplicate elements.
// The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).


#include <iostream>
#include <algorithm>
using namespace std;

// #include "solution.h"

void intersection(int *arr1, int *arr2, int n, int m) {
    // sort arr1 and arr2
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    // resulting arr3 is of size same as smaller array
    int size {0};
    if (m < n) {
        size = m;
    }
    else {
        size = n;
    }

    int *arr3= new int[size];

    int i {0};
    int j {0};

    size = 0;

    while (i < n && j < m) {
        if(arr1[i] == arr2[j]) {
            arr3[size] = arr1[i];
            ++i;
            ++j;
            // std::cout << arr3[size] << endl;
            ++size;
        }
        else if (arr1[i] < arr2[j]) {
            ++i;
        }
        else if (arr1[i] > arr2[j]) {
            ++j;
        }
    }

    for (int i = 0; i < size; ++i) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    delete[] arr3;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}
