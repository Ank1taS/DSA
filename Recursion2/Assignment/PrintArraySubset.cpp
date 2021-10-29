// Given an integer array (of length n), find and print all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. 
// But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print the subsets in different lines.

#include <iostream>
using namespace std;
// #include "solution.h"

void helper(int input[], int inputSize, int output[], int outputSize) {
    if (inputSize == 0) {
        for (int i = 0; i < outputSize; ++i) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    int* newOutput = new int[outputSize + 1];

    for (int i = 0; i < outputSize; ++i) {
        newOutput[i] = output[i];
    }
    newOutput[outputSize] = input[0];

    helper(input + 1, inputSize - 1, output, outputSize);
    helper(input + 1, inputSize - 1, newOutput, outputSize + 1);

    delete[] newOutput;
}

void printSubsetsOfArray(int input[], int size) {
    int* output = new int[1];    

    helper(input, size, output, 0);
    delete[] output;
}

int main() {
  int input[1000],length;

  cin >> length;
  
  for(int i=0; i < length; i++)
  	cin >> input[i];
  
  printSubsetsOfArray(input, length);

  return 0;
}
