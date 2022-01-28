// <!-- Sudoku Solver

// Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
// You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.

// Input Format:
// There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.

// Output Format:
// The first and only line of output contains boolean value, either true or false, as described in problem statement.

// Constraints:
// The cell values lie in the range: [0, 9]
// Time Limit: 1 second 

// Note:
// Input are given in a way that backtracking solution will work in the provided time limit.

// Sample Input 1:
// 9 0 0 0 2 0 7 5 0 
// 6 0 0 0 5 0 0 4 0 
// 0 2 0 4 0 0 0 1 0 
// 2 0 8 0 0 0 0 0 0 
// 0 7 0 5 0 9 0 6 0 
// 0 0 0 0 0 0 4 0 1 
// 0 1 0 0 0 5 0 8 0 
// 0 9 0 0 7 0 0 0 4 
// 0 8 2 0 4 0 0 0 6

// Sample Output 1:
// true -->


#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0

#define N 9
bool FindUnassignedLocation(int grid[N][N],
                            int& row, int& col);

bool isSafe(int grid[N][N], int row,
            int col, int num);

bool SolveSudoku(int grid[N][N])
{
    int row, col;
 
    if (!FindUnassignedLocation(grid, row, col))
        // success!
        return true;
 
    // Consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
         
        // Check if looks promising
        if (isSafe(grid, row, col, num))
        {
             
            // Make tentative assignment
            grid[row][col] = num;
 
            // Return, if success
            if (SolveSudoku(grid))
                return true;
 
            // Failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    
    // This triggers backtracking
    return false;
}
bool FindUnassignedLocation(int grid[N][N],
                            int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool UsedInBox(int grid[N][N], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] ==
                                       num)
                return true;
    return false;
}
 
bool isSafe(int grid[N][N], int row,
            int col, int num)
{
    return !UsedInRow(grid, row, num)
           && !UsedInCol(grid, col, num)
           && !UsedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == UNASSIGNED;
}
// Driver Code
int main()
{
    // 0 means unassigned cells
    int grid[N][N];
    
    for (int i{0}; i<N; i++)
        for(int j{0}; j<N; j++)
            cin>>grid[i][j];
    
    if (SolveSudoku(grid) == true)
        cout<<"true";
    else
        cout<<"false";
 
    return 0;
}




