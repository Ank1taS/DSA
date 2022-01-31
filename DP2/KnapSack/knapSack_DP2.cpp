// bug

#include <cstring>
#include <iostream>
using namespace std;



// considering currentIndex = row of outPut
// considering maxweight = col of outPut



int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **outPut {new int*[n + 1]};
    for (int i {0}; i <= n; ++i) {
        outPut[i] = new int[maxWeight + 1];
    }

    // fill nth row with 0
    for (int i {0}; i <= maxWeight; ++i) {
        outPut[n][i] = 0;
    }

    // fill 0th column with 0
    for (int i {0}; i <= n; ++i) {
        outPut[i][0] = 0;
    }

    for (int i {n - 1}; i >= 0; --i) {
        for (int j {1}; j <= maxWeight; ++j) {
            // recursive calls if result not found
            if(weight[j] > maxWeight) {
                // outPut[currentIndex][maxWeight] = knapsack(weight, value, endIndex, maxWeight, currentIndex + 1, outPut);
                // return outPut[currentIndex][maxWeight];
                outPut[i][j] = outPut[i + 1][j];

            }
            else {
                // recursive call including current index
                int x {value[j] + outPut[i + 1][j - weight[j]]};
                // recursive call excluding current index
                int y {outPut[i + 1][j]}; 

                outPut[i][j] = max(x, y);
            }
        }
    }

    int result = outPut[n][maxWeight];

    for (int i {0}; i <= n; ++i) {
        delete[] outPut[i];
    }

	return result;
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}