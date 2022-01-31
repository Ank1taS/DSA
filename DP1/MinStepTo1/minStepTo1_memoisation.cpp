#include <bits/stdc++.h>
using namespace std;


int countMinStepsToOneHelper(int *arr, int n) {
	if (n <= 1) {
        return arr[0];  // return 0
    }

    // checks if steps to solve n exists
    if (arr[n] != -1) {
        return arr[n];
    }

    // stores total steps required to get 1 by reducing num by 1
    int count1 {countMinStepsToOneHelper(n - 1)};
    int count2 {INT_MAX};
    int count3 {INT_MAX};

    // stores total steps required to get 1 by dividing num by 2 if num is divisible by 2
    if (n % 2 == 0) {
        count2 = countMinStepsToOneHelper(n / 2);
    }
    
    // stores total steps required to get 1 by dividing num by 3 if num is divisible by 3
    if (n % 3 == 0) {
        count3 = countMinStepsToOneHelper(n / 3);
    }

    arr[n] = 1 + min(count1, min(count2, count3));
    return arr[n];
}

int countMinStepsToOne(int n) {
    // base case
    if (n == 1) {
        return 0;
    }

    int *arr = new int[n];
    for (int i {0}; i < n; ++i) {
        arr[i] = -1;
    }

    return countMinStepsToOneHelper(arr, n);
}

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);

    return 0;
}