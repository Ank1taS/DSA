// Given an array A of size n and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. 
// But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important.

#include <iostream>
// #include "solution.h"
using namespace std;


void printSubsetSumToK(int input[], int size, int k, string output="") {
    // Write your code here
    if(size == 0)
    {
        if(k == 0)
        {
            cout << output << endl;
            return;
        }
        return;
    }
    printSubsetSumToK(input + 1, size - 1, k, output);
    printSubsetSumToK(input + 1, size - 1, k - input[0], output + to_string(input[0]) + " ");
}

int main() {
  int input[1000], length, k;
  cin >> length;

  for(int i = 0; i < length; i++)
    cin >> input[i];
  
  cin >> k;
  printSubsetSumToK(input, length, k);

  return;
}
