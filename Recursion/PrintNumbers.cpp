// Given is the code to print numbers from 1 to n in increasing order recursively

#include<iostream>
using namespace std;
// #include "Solution.h"

void print(int n){
    if(n == 0){
        return;
    }
    
    print(n - 1);
    cout << n << " ";
}

int main(){
    int n;
    cin >> n;
  
    print(n);
}

