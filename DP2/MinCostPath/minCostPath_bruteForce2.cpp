// Time complexity is aprox 3 ^ n
// coding ninja solution


#include <iostream>

int minCostPath(int **input, int m, int n, int i, int j) {
	// Base case
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}

	// Recursive calls
	int x = minCostPath(input, m, n, i, j+1);
	int y = minCostPath(input, m, n, i+1, j+1);
	int z = minCostPath(input, m, n, i+1, j);

	// Small Calculation
	int ans = min(x, min(y, z)) + input[i][j];
	return ans;
}

int minCostPath(int **input, int m, int n) {
	return minCostPath(input, m, n, 0, 0);
}

int main() {
	int m, n;
	cin >> m >> n;
	int **input = new int*[m];
	for(int i = 0; i < m; i++) {
		input[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> input[i][j];
		}	
	}
	cout << minCOst_DP(input, m, n) << endl;
	cout << minCostPath_Better(input, m, n) << endl;
	cout << minCostPath(input, m, n) << endl;
}