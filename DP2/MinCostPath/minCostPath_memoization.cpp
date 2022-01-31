// time complexity  - O(n*m)
// space complexity - O(n*m)



#include <iostream>
using namespace std;
#include <climits>

int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output) {
    if(i == m- 1 && j == n- 1) {
        return input[i][j];
    }
    
    if(i >= m || j >= n) {
        return INT_MAX;
    }
    
    // Check if ans already exists
    if(output[i][j] != -1) {
        return output[i][j];
    }
    
    // Recursive calls
    int x = minCostPath_Mem(input, m, n, i, j+1, output);
    int y = minCostPath_Mem(input, m, n, i+1, j+1, output);
    int z = minCostPath_Mem(input, m, n, i+1, j, output);
    
    // Small Calculation
    int a = min(x, min(y, z)) + input[i][j];
    
    // Save the answer for future use
    output[i][j] = a;
    
    return a;
}

int minCostPath_Mem(int **input, int m, int n, int i, int j) {
    int **output = new int*[m];
    for(int i = 0; i < m; i++) {
        output[i] = new int[n];
        for(int j = 0; j < n; j++) {
            output[i][j] = -1;
        }
    }
    
    return minCostPath_Mem(input, m, n, i, j, output);
}

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
    cout << minCostPath_Mem(input, m, n, 0, 0) << endl;
    cout << minCostPath(input, m, n) << endl;
}