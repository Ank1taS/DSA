#include <cstring>
#include <iostream>
using namespace std;

// considering currentIndex = row of outPut
// considering maxweight = col of outPut

int knapsack(int *weight, int *value, int maxWeight, int n, int **outPut) {
    // base case 
    if (n == 0 || maxWeight == 0) {
        return 0;
    }

    // checks for result on outPut[][]
    if (outPut[n][maxWeight] != -1) {
        return outPut[n][maxWeight];
    }
    
    int ans;

    // recursive calls if result not found
    if(weight[0] > maxWeight) {
		// outPut[currentIndex][maxWeight] = knapsack(weight, value, endIndex, maxWeight, currentIndex + 1, outPut);
        // return outPut[currentIndex][maxWeight];
        ans = knapsack(weight + 1, value + 1, maxWeight, n - 1, outPut);

	}
    else {
        // recursive call including current index
        int x {value[0] + knapsack(weight + 1, value + 1, maxWeight - weight[0], n - 1, outPut)};
        // recursive call excluding current index
        int y {knapsack(weight + 1, value + 1, maxWeight, n - 1, outPut)};

        ans = max(x, y);
    }

    outPut[n][maxWeight] = ans;

    return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **arr {new int*[n + 1]};
    for (int i {0}; i <= n; ++i) {
        arr[i] = new int[maxWeight + 1];
        for (int j {0}; j <= maxWeight; ++j) {
            arr[i][j] = -1;
        }
    }


    int result {knapsack(weight, value, maxWeight, n, arr)};
    for (int i {0}; i <= n; ++i) {
        delete[] arr[i];
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