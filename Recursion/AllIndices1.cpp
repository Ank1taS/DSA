/* Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. 
Save all the indexes in an array (in increasing order). 
recursion call  -  [][][] || []
*/
#include<iostream>
// #include "Solution.h"
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
    // base case
    if (size == 0) {
        return 0;
    }
    // recursive call
    int count = allIndexes(input, size - 1, x, output);

    if (input[size - 1] == x) {
        output[count] = size - 1;
        count += 1;
    }    
    return count;
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    delete [] output;
    
    return 0;
}


