// You have been given an integer array/list(ARR) and a number 'num'. 
// Find and return the total number of pairs in the array/list which sum to 'num'.

// Note:
// Given array/list can contain duplicate elements. 


#include <iostream>
#include <algorithm>
using namespace std;

// #include "solution.h"

int pairSum(int *arr, int n, int num)
{
    sort(arr, arr + n);

	int count {0};
    int i {0}, j {n - 1};

    while (i < j) {
        if (arr[i] + arr[j] < num) {
            ++i;
        }
        else if (arr[i] + arr[j] > num) {
            --j;
        }
        else if (arr[i] + arr[j] == num) {
            int num1 = arr[i];
            int num2 = arr[j];
            int num1count {1};
            int num2count {1};

            for (int k = i + 1 ; k < n; ++k) {
                if (arr[k] == num1) {
                    ++num1count;
                }
                else {
                    break;
                }
            }
			
            // if all the element of array is same
            if (num1count + i == n) {
                ++i;
                count += num1count - 1;
                continue;
            }
            
            for (int k = j -1 ; k >= 0; --k) {
                if (arr[k] == num2) {
                    ++num2count;
                }
                else {
                    break;
                }
            }

            count += (num1count * num2count);
            i += num1count;
            j -= num2count;
        }
    }

    return count;
}

int main()
{
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

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}