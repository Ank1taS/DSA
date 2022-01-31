#include <bits/stdc++.h>
using namespace std;

int minCount(int n) {
    // base case
    // if n <= 0, there is no way to get to 1, return 0
	if (n <= 0) {
        return 0;
    }

    // minimumCount stores total count to get to 1
    int minimumCount {INT_MAX};
    
    int divFactor {1};

    // divFactor can be max till (squreRoot of divFactor)'s squre is less than equals n
    while (divFactor * divFactor <= n) {
        // temp store smaller solution result from reccursion
        int temp {minCount(n - (divFactor * divFactor))};
        
        // if it is less that minimumCount then store it with updating current step
        if (temp < minimumCount) {
            minimumCount = 1 + temp;
        }
        // update divFactor
        ++divFactor;
    }

    return minimumCount;    
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}