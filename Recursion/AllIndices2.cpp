// Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. 
// Save all the indexes in an array (in increasing order).
// recursion call  -  [] || [][][]

#include<iostream>
// #include "Solution.h"
using namespace std;

int allIndexes(int input[], int size, int x, int output[]) {
    // base case
    if (size == 0) {
        return 0;
    }
    // recursive call
    int count = allIndexes(input + 1, size - 1, x, output);

    if (count != 0) {
        for (int i = 0; i < count; ++i) {
            output[i] += 1;
        }
    }

    if (input[0] == x) {
        for (int i = count - 1; i >= 0; --i) {
            output[i + 1] = output[i];
        }
        output[0] = 0;
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
