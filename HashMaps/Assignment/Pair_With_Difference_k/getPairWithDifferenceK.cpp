// You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
// Note: Take absolute difference between the elements of the array


#include <iostream>
#include <unordered_map>
using namespace std;

int getPairsWithDifferenceK(int *input, int n, int k) {
    unordered_map<int, int> mp;

    for (int i {0}; i < n; ++i) {
        mp[input[i]]++;
    }

    int totalPairCount {0};

    if (k == 0) {
        for (int i {0}; i < n; ++i) {
            if (mp[input[i]] != 1) {
                totalPairCount += mp[input[i]] - 1;
                --mp[input[i]];
            }
        }
        return totalPairCount;
    }
    
    for(int i {0}; i < n; ++i) {
        int pairNum1 {input[i] - k};
        int pairNum2 {input[i] + k};

        if (mp.count(pairNum1) > 0) {
            totalPairCount += mp[input[i]] * mp[pairNum1];
        }
        
        if (mp.count(pairNum2) > 0) {
            totalPairCount += mp[input[i]] * mp[pairNum2];
        	// mp.erase(i);
        }
        mp.erase(input[i]);
    }

    return totalPairCount;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}