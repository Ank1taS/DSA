// Given an integer array (of length n), find and return all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. 
// But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important

#include <iostream>
// #include "solution.h"
using namespace std;

int subset(int input[], int n, int output[][20]) {
    if (n == 0) {
        output[0][0] = 0;
        output[0][1] = 0;

        return 1;
    }

    int smallOutputSize = subset(input + 1, n - 1, output);

    for (int i = 0; i < smallOutputSize; ++i) {
        output[smallOutputSize + i][0] = output[i][0] + 1;  
        output[smallOutputSize + i][1] = input[0];

        for (int j = 1; j <= output[i][0]; ++j) {
            output[smallOutputSize + i][j + 1] = output[i][j];
        }
    }
    return 2 * smallOutputSize;
}

int main() {
    int input[20],length, output[3500][20];
    
    cin >> length;
    
    for(int i=0; i < length; i++)
      cin >> input[i];
    
    int size = subset(input, length, output);

    for( int i = 0; i < size; i++) { 
        for( int j = 1; j <= output[i][0]; j++) { 
          cout << output[i][j] << " ";
        }
      cout << endl;
    }
}

