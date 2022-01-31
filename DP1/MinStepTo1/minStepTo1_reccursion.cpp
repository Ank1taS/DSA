#include <bits/stdc++.h>
using namespace std;


int countMinStepsToOne(int n) {
	if (n <= 1) {
        return 0;
    }

    // stores total steps required to get 1 by reducing num by 1
    int count1 {countMinStepsToOne(n - 1)};
    int count2 {INT_MAX};
    int count3 {INT_MAX};

    // stores total steps required to get 1 by dividing num by 2 if num is divisible by 2
    if (n % 2 == 0) {
        count2 = countMinStepsToOne(n / 2);
    }
    
    // stores total steps required to get 1 by dividing num by 3 if num is divisible by 3
    if (n % 3 == 0) {
        count3 = countMinStepsToOne(n / 3);
    }

    return 1 + min(count1, min(count2, count3));
}

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);

    return 0;
}