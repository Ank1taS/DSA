// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
// Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.

#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;
int charToInt(char a)
{
    int i = a - '0';

    return i;
}
char intToChar(int i)
{
    char c = 'a' + i - 1;
    return c;
}
void helper(string input, string output) {
   if(input.size() == 0)
   {
       cout << output << endl;
       return;
   }
    
    string result1 = output;
    string result2 = output;
    
    helper(input.substr(1), result1 + intToChar(charToInt(input[0])));

    if(input.size() > 1)
    {
        if(charToInt(input[0]) * 10 + charToInt(input[1]) > 10 && charToInt(input[0]) * 10 + charToInt(input[1]) < 27)
        {
            helper(input.substr(2), result2 + intToChar(charToInt(input[0]) * 10 + charToInt(input[1])));
        }

    }
}

void printAllPossibleCodes(string input) {
    string output = "";

    helper(input, output);
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
