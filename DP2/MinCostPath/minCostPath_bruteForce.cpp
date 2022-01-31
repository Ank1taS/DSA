#include <bits/stdc++.h>
using namespace std;


int minCostPathHelper(int **input, int rowSize, int columnSize, int rowCurrent, int columnCurent) {
    // base case
    if (rowCurrent == rowSize - 1 && columnCurent == columnSize - 1) {
        return input[rowCurrent][columnCurent];
    }

    int downResult {INT_MAX};
    int rightResult{INT_MAX};
    int diagonalResult {INT_MAX};

    if (rowCurrent + 1 < rowSize) {
        downResult = minCostPathHelper(input, rowSize, columnSize, rowCurrent + 1, columnCurent);
    }
    if (columnCurent + 1 < columnSize) {
        rightResult = minCostPathHelper(input, rowSize, columnSize, rowCurrent, columnCurent + 1);
    }
    if (rowCurrent + 1 < rowSize && columnCurent + 1 < columnSize) {
        diagonalResult = minCostPathHelper(input, rowSize, columnSize, rowCurrent + 1, columnCurent + 1);
    }

    int finalResult {input[rowCurrent][columnCurent] + min(downResult, min(rightResult, diagonalResult))};
    return finalResult;
}

int minCostPath(int **input, int m, int n) {
	//Write your code here
    return minCostPathHelper(input, m, n, 0, 0);
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}