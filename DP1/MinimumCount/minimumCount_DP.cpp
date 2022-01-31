#include <bits/stdc++.h>
using namespace std;



int minCount(int n) {
    if (n <= 0) {
        return 0;
    }

    int *arr {new int[n + 1]};
    arr[0] = 0;
    arr[1] = 1;

    for(int i {2}; i <= n; ++i) {

        arr[i] = INT_MAX;

        for (int j {1}; j * j <= i; ++j) {
            arr[i] = min(arr[i], arr[i - (j * j)]);
        }
        ++arr[i];

        /*
        // alternet approch
        int minimumCount {INT_MAX};
        
        for (int j {1}; j * j <= i; ++j) {
            if(arr[i - (j * j)] < minimumCount) {
                minimumCount = arr[i - (j * j)];
            }
        }
    
        arr[i] = 1 + minimumCount;
        */
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