// time complexity  - O(n*m)
// space complexity - O(n*m)



#include <iostream>
using namespace std;
#include <climits>


int minCostPath(int **inPut, int rowSize, int colSize) {
	// create output 2d array of exact size as input 
	// to store min cost path to [rowSize - 1][colSize -1] of each index 
	int **outPut {new int*[rowSize]};
	for (int i {0}; i < rowSize; ++i) {
		outPut[i] = new int[colSize];
	}

	// store the result of [rowSize - 1][colSize -1] of input in outPut array
	outPut[rowSize - 1][colSize -1] = inPut[rowSize - 1][colSize -1];

	// fill last row with it's minCost path to [rowSize - 1][colSize -1] - fill from right to left
	for (int i {colSize - 2}; i >= 0; --i) {
		outPut[rowSize - 1][i] = inPut[rowSize - 1][i] + outPut[rowSize - 1][i + 1];
	}

	// fill last column with it's minCost path to [rowSize - 1][colSize -1] - fill from down to up
	for (int i {rowSize - 2}; i >= 0; --i) {
		outPut[i][colSize - 1] = inPut[i][colSize - 1] + outPut[i + 1][colSize - 1];
	}

	// fill rest of index row wise - down to up
	for (int i {rowSize - 2}; i >= 0; --i) {
		// fill each rows each col - right to left
		for (int j {colSize - 2}; j >= 0; --j) {
			outPut[i][j] = inPut[i][j] + min(outPut[i + 1][j + 1], min(outPut[i][j + 1], outPut[i + 1][j]));
		}
	}

	int result {outPut[0][0]};
	for (int i {0}; i <= rowSize; ++i) {
        delete[] outPut[i];
    }
	return result;
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
	cout << minCostPath(input, m, n) << endl;
}