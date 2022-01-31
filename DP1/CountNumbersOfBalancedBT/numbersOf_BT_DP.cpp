#include <iostream>
#define mod 1000000007          // mod = pow(10, 9) + 7
using namespace std;

int balancedBTs(int n) {

    // edge case
    if (n < 0) {
        return 0;
    }

    int *arr {new int[n + 1]};
    arr[0] = 1;
    arr[1] = 1;

    for (int i {2}; i <= n; ++i) {
        int x {arr[i - 1]};
        int y {arr[i - 2]};

        // total possible combinations : n - 1 & n - 1, n - 1 & n - 2, n - 2 & n - 1
        int temp1 {(int) (((long) x * x) % mod)};
        int temp2 {(int) ((2 * (long) x * y) % mod)};
        
        int result {(temp1 + temp2) % mod};
        arr[i] = result;
    }

    int result {arr[n]};
    delete [] arr;

    return result;
}


int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}