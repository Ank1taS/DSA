// Given an array of length N, you need to find and return the sum of all elements of the array

#include<iostream>
// #include "Solution.h"
using namespace std;

int sum(int input[], int n) {
    if (n == 0) {
        return 0;
    }

    return (input[0] + sum(++input, --n));
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}
