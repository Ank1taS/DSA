// You have been given a random integer array/list(ARR) and a number X. 
// Find and return the triplet(s) in the array/list which sum to X.
// Note :
// Given array/list can contain duplicate elements.


#include <iostream>
#include <algorithm>
using namespace std;

// #include "solution.h"

int tripletSum(int *arr, int n, int num) {
    sort(arr, arr + n);

    int tripletCount {0};

    for (int l {0}; l < n - 2; ++l) {
        int pairsumElement = num - arr[l];

        int count {0};
        int i {l + 1}; 
        int j {n - 1};

        while (i < j) {
            if (arr[i] + arr[j] < pairsumElement) {
                ++i;
            }
            else if (arr[i] + arr[j] > pairsumElement) {
                --j;
            }
            else if (arr[i] + arr[j] == pairsumElement) {
                int num1 = arr[i];
                int num2 = arr[j];
                int num1count {1};
                int num2count {1};  

                for (int k = i + 1 ; arr[k] == num1; ++k) {
                    ++num1count;
                }
                
                // if all the element of array is same
                if (num1count + i == n) {
                    ++i;
                    count += num1count - 1;
                    continue;
                }
                
                if (i + num1count - 1 == j) {
                    ++i;
                    count += num1count - 1;
                    continue;
                }

                for (int k = j -1 ; arr[k] == num2; --k) {
                    ++num2count;
                }

                count += (num1count * num2count);
                i += num1count;
                j -= num2count;
            }
        }

        tripletCount += count;
    }

    return tripletCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;
        
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}