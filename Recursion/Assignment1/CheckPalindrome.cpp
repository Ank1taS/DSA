// Check whether a given String S is a palindrome using recursion. Return true or false.

#include <iostream>
#include <cstring>
// #include "solution.h"
using namespace std;

bool helper(char input[], int size) {
    if (size == 0 || size == 1) {
        return true;
    }

    if (input[0] == input[size - 1]) {
        return helper(input + 1, size - 2);
    }
    else {
        return false;
    }
}

bool checkPalindrome(char input[]) {
    int size = strlen(input);

    return helper(input, size);
}


int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
