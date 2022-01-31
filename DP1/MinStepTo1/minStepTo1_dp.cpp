#include <bits/stdc++.h>
using namespace std;

int countMinStepsToOne(int n) {   
    int *arr = new int[n+1];

    arr[0] = 0;
    arr[1] = 0;

    for (int i {2}; i <= n; ++i) {

        // stores total steps required to get 1 by reducing num by 1
        int count1 {arr[i - 1]};
        int count2 {INT_MAX};
        int count3 {INT_MAX};

        // stores total steps required to get 1 by dividing num by 2 if num is divisible by 2
        if (i % 2 == 0) {
            count2 = arr[i / 2];
        }
        
        // stores total steps required to get 1 by dividing num by 3 if num is divisible by 3
        if (i % 3 == 0) {
            count3 = arr[i / 3];
        }

        arr[i] = 1 + min(count1, min(count2, count3));
    }

    int result {arr[n]};
    delete arr;
    
    return result;
}

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);

    return 0;
}