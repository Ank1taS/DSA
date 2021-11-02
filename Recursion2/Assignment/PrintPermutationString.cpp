// Given an input string (STR), print all possible permutations of the input string.
// Note:
// The input string may contain the same characters, so there will also be the same permutations.
// The order of permutations doesn’t matter.

#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

void helper(string input, string output) {
    if (input.empty()) {
        cout << output << endl;
        return;
    }

    for (int i = 0; i < input.size(); ++i) {
        helper(input.substr(0, i) + input.substr(i + 1), output + input[i]);
    }
}

void printPermutations(string input){
    helper(input, "");
}

int main() {
    string input;
    cin >> input;

    printPermutations(input);
    
    return 0;
}
