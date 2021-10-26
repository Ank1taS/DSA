// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note :   1. The order of strings are not important.
//          2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

// #include <string>
// using namespace std;

int helper(int num, string output[], const string keyboard[]) {
    if (num == 0) {
        output[0] = "";
        return 1;
    }

    int count;
    int currentDigit = num % 10;
    int outputSize = helper(num / 10, output, keyboard);
    int index = outputSize;

    count = keyboard[currentDigit].size();

    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < outputSize; ++j) {
            output[index++] = output[j];
        }
    }

    index = 0;
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < outputSize; ++j) {
            output[index++] += keyboard[currentDigit][i];
        }
    }
    outputSize *= keyboard[currentDigit].size();

    return outputSize;
}

int keypad(int num, string output[]){
    const string keyboard[] = { " ",
                                " ",
                                "abc",
                                "def",
                                "ghi",
                                "jkl",
                                "mno",
                                "pqrs",
                                "tvu",
                                "wxyz"};

    return helper(num, output, keyboard);
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);

    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    
    return 0;
}