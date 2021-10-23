// Given the code to find out and return the number of digits present in a number recursively


#include<iostream>
// #include "Solution.h"
using namespace std;

int count(int n){
    if(n == 0){
        return 0;
    }

    return (count(n / 10) + 1);
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;

    return 0;
}

