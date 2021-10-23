// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.

#include <iostream>
// #include "solution.h"
using namespace std;

int countZeros(int n) {
    if (n / 10 == 0) {
        if (n == 0) {
            return 1;
        }
        return 0;
    }

    int count = countZeros(n / 10);

    if (n % 10 == 0) {
        return count + 1;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;

    return 0;
}

// 2040