#include <bits/stdc++.h>
using namespace std;



int minCount(int n) {
    if (n <= 3) {
        return n;
    }

    int *arr {new int[n + 1]};
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    for(int i {4}; i <= n; ++i) {

        arr[i] = INT_MAX;

        for (int j {1}; j * j <= i; ++j) {
            arr[i] = min(arr[i], arr[i - (j * j)]);
        }
        ++arr[i];
    }

    int result {arr[n]};
    
    delete [] arr;
    return result; 
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}