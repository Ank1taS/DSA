#include <iostream>
// #include "solution.h"
using namespace std;

bool helper(int *input, int size, int index, int sumOf3, int sumOf5) {
    // If reached the end
    if (index == size) {
        return sumOf3 == sumOf5;
    }

    // If divisible by 5 then add to the sumOf5
    if (input[index] % 5 == 0) {
        sumOf5 += input[index];
    }
    // If divisible by 3 then add to the sumOf3
    else if (input[index] % 3 == 0) {
        sumOf3 += input[index];
    }
    // Else it can be added to any of the sub-arrays
    else{
        // Try adding in both the sub-arrays (one by one)
        // and check whether the condition satisfies
        return helper(input, size, index + 1, sumOf3 + input[index], sumOf5) || helper(input, size, index + 1, sumOf3, sumOf5 + input[index]);
    }
    
    return helper(input, size, index + 1, sumOf3, sumOf5);
}

bool splitArray(int *input, int size) {
    return helper(input, size, 0, 0, 0);   
}

int main() {
	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
	
	return 0;
}
