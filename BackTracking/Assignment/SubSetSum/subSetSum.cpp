// Subset Sum

// You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.

// Note:
// 1. Subset can have duplicate values.
// 2. Empty subset is a valid subset and has sum equal to zero.


// Input Format:
// The first line of input will contain an integer T, that denotes the value of number of test cases.
// Each test case contains two lines. The first line of each test case will contain two space-separated integers N and K, where N is the size of the given array and K is the target value. 
// The second line of each test case will contain N space separated integers denoting the elements of the input array.

// Output Format ;
// For each test case, print the number of subsets that sum upto K in a separate line.

// Constraints
// 1 <= T <= 50
// 2 <= N <= 15
// 0 <= array[i] <= 10^9
// 0 <= K <= 10^9
// Time Limit: 1 second

// Sample Input 1:
// 1
// 5 6
// 2 4 4 3 1

// Sample Output 1:
// 3

// Explanation:
// Following are the three subsets, that sum upto K=6:
// 1. [2, 4], Element 4 in this subset is the one at index 1
// 2. [2, 4], Element 4 in this subset is the one at index 2
// 3. [2, 3, 1]  

// Sample Input 2:
// 2
// 8 8
// 1 4 1 3 1 1 2 3 
// 8 2
// 4 1 4 4 2 4 1 1

// Sample Output 2:
// 30
// 4

// ==========================================================================================================================

#include<bits/stdc++.h>
using namespace std;

// subSetSumHelper() 
// takes arr , size - arr size, key - target sum, pos - current index position from which itteration begin, sum - current sum, count - total sunsets that sum up to key a reference. so any change in count will reflect in calling function
void subSetSumHelper(int *arr, int size, int key, int pos, int sum, int &count) {
    if (pos == size) {
        return;
    }

    // sum += arr[pos];
    for (int i {pos}; i < size; ++i) {
        if (sum + arr[i] == key && sum != 0) {
            ++count;
            sum += arr[i];
        }
        else if (sum + arr[i] < key) {
            sum += arr[i];
        }

        subSetSumHelper(arr, size, key, i + 1, sum, count);

        if (sum - arr[i] > 0) {
            sum -= arr[i];
        }
    }
}

// subsetsum() - returns total numbers of sub sets of arr that sum ip to key
int subSetSum(int *arr, int size, int key) {
    int count {0};
    subSetSumHelper(arr, size, key, 0, 0, count);

    return count; 
}

int main(){
    
    int testCases;
    int size;
    int key;
    cin >> testCases;

    for (int i {0}; i < testCases; ++i) {
        cin >> size >> key;
        int *arr = new int[size];

        for (int j {0}; j < size; ++j) {
            cin >> arr[i];
        }

        cout << subSetSum(arr, size, key) << endl;
    }
    
    
    return 0;
}

