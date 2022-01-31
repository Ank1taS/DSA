#include <iostream>
using namespace std;

long staircaseHelper(long *arr, int n) {
    // base case
    if (n <= 1) {
        return 1;
    }
    // edge case
    else if (n == 2) {
        return 2;
    }

    // if result exist
    if (arr[n] != 0) {
        return arr[n];
    }

    // posssible count to reach to stair number n is the sum of possible count to reach to stair n - 1, n- 2 and n - 3
    arr[n] = staircaseHelper(arr, n - 1) + staircaseHelper(arr, n - 2) + staircaseHelper(arr, n - 3);
    
    return arr[n];
}
long staircase(int n)
{
	//Write your code here
    long *arr {new long[n + 1] ()};

    long result {staircaseHelper(arr, n)};
    delete []arr;

    return result;
}


int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}