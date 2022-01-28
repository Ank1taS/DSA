// Rat In A Maze Problem
//
// You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
// In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
// You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.


/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;



void printSolution(int** solution,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << solution[i][j] << " ";
		}
	}
	cout<<endl;
}
void mazeHelp(int **maze,int n,int** solution,int x,int y){


	if(x == n-1 && y == n-1){
		solution[x][y] =1;
		printSolution(solution,n);
      	solution[x][y] =0;
		return;
	}
	if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || solution[x][y] ==1){
		return;
	}
	solution[x][y] = 1;
	mazeHelp(maze,n,solution,x-1,y);
	mazeHelp(maze,n,solution,x+1,y);
	mazeHelp(maze,n,solution,x,y-1);
	mazeHelp(maze,n,solution,x,y+1);
	solution[x][y] = 0;
}
void ratInAMaze(int **maze, int n){

  int** solution = new int*[n];
  for(int i=0;i<n;i++){
  	solution[i] = new int[n];
  }
  mazeHelp(maze,n,solution,0,0);


}

int main() {

	// Write your code here
    int n;
    cin >> n;

    int **arr = new int*[n];
    for (int i {0}; i < n; ++i) {
        arr[i] = new int[20];
    }
    
    for (int i {0}; i < n; ++i) {
        for (int j {0}; j < n; ++j) {
            int element;
            cin >> element;
            arr[i][j] = element;
        }
    }

    ratInAMaze(arr, n);
	return 0;
}
