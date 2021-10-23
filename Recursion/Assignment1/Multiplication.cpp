// Given two integers M & N, calculate and return their multiplication using recursion.
//  You can only use subtraction and addition for your calculation. No other operators are allowed.

#include <iostream>
// #include "solution.h"
using namespace std;

int multiplyNumbers(int m, int n) {
    if (m == 0) {
        return 0;
    }
    else if (m == 1) {
        return n;
    }

    return multiplyNumbers(n, m - 1) + n;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
