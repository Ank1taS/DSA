// Suppose you have a string, S, made up of only 'a's and 'b's. 
// Write a recursive function that checks if the string was generated using the following rules:
//      a. The string begins with an 'a'
//      b. Each 'a' is followed by nothing or an 'a' or "bb"
//      c. Each "bb" is followed by nothing or an 'a'
// If all the rules are followed by the given string, return true otherwise return false.

#include <iostream>
// #include "solution.h"
using namespace std;

bool checkAB(char input[]) {
    if (input[0] == '\0') {
        return true;
    }

    if (input[0] == 'a') {
        if (input[1] == 'a' || input[1] == '\0') {
            checkAB(input + 1);
        }

        else if (input[1] == 'b' || input[2] == 'b') {
            if (input[3] == 'a' || input[3] == '\0') {
                checkAB(input + 3);
            }
            else {
                return false;
            }
        }

        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int main() {
    char input[100];
    bool ans;

    cin >> input;
    ans = checkAB(input);

    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;

    return 0;
}
