// Write a recursive function to convert a given string into the number it represents. 
// That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.


#include <iostream>
#include <cstring>
// #include "solution.h"
using namespace std;

int helper(char input[], int size) {
    if (size == 1) {
        return int(input[size - 1]) - 48;       // int(input[0]) - 48
    }
   
    return ((helper(input, size - 1) * 10)+ (int (input[size - 1]) - 48));
}

int stringToNumber(char input[]) {
    int size = strlen(input);

    return helper(input, size);
}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}

