#include <iostream>
#define mod 1000000007          // mod = pow(10, 9) + 7
using namespace std;

int balancedBTs(int n) {

    // edge case
    if (n < 0) {
        return 0;
    }

    // base case
    if (n == 0 || n == 1) {
        return 1;
    }

    // recursive call to get total possible balanced BT for n - 1 and n - 2
    int x {balancedBTs(n - 1)};
    int y {balancedBTs(n - 2)};

    // total possible combinations : n - 1 & n - 1, n - 1 & n - 2, n - 2 & n - 1
    int temp1 {(int) (((long) x * x) % mod)};
    int temp2 {(int) ((2 * (long) x * y) % mod)};

    int result {(temp1 + temp2) % mod};
    
    return result;
}


int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}