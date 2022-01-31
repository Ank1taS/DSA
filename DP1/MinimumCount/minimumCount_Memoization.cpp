#include <bits/stdc++.h>
using namespace std;


int minCountHelper(int *arr, int n) {
    if (n <= 0) {
        return 0;
    }

    if (arr[n] != 0) {
        return arr[n];
    }

    int minimumCount {INT_MAX};
    int divFactor {1};

    // divFactor can be max till (squreRoot of divFactor)'s squre is less than equals n
    while (divFactor * divFactor <= n) {
        // temp store smaller solution result from reccursion
        int temp {minCountHelper(arr, n - (divFactor * divFactor))};
        
        // if it is less that minimumCount then store it with updating current step
        if (temp < minimumCount) {
            minimumCount = 1 + temp;
        }
        // update divFactor
        ++divFactor;
    }

    arr[n] = minimumCount;

    return arr[n]; 
}


int minCount(int n) {
    int *arr {new int[n + 1] ()};

    return minCountHelper(arr, n);    
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}