// You have been given a random integer array/list(ARR) and a number X. 
// Find and return the triplet(s) in the array/list which sum to X.
// Note :
// Given array/list can contain duplicate elements.


#include <iostream>
#include <algorithm>
using namespace std;

// #include "solution.h"

int tripletSum(int *arr, int n, int num) {
	//Write your code here
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
                
                if (arr[i] == arr[j])
        		{
            		int no_of_elements = j - i + 1; 
            		count += no_of_elements * (no_of_elements - 1) / 2;
                    break;
        		}
                else{
                    for (int k = i + 1 ; k < n; ++k) {
                        if (arr[k] == num1) {
                            ++num1count;
                        }
                        else {
                            break;
                        }
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
        }

        tripletCount += count;
    }

    return tripletCount;
}

int main() {
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