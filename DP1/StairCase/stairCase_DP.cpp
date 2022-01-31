#include <iostream>
using namespace std;

long staircase(int n) {
    // arr to store total possible count of an index to reach it from 0 or base 
	long *arr {new long[n + 1]};

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for (int i {3}; i <= n; ++i) {
        // posssible count to reach to stair number n is the sum of possible count to reach to stair n - 1, n- 2 and n - 3
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }

    long result {arr[n]};
    delete []arr;
    
    return result;
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}