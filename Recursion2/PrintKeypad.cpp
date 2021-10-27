// Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
// Note : The order of strings are not important. Just print different strings in new lines

#include <iostream>
#include <string>
// #include "solution.h"
using namespace std;

void helper(int num, const string keyboard[], string output = "") {
    if (num == 0) {
        cout << output << endl;
        return;
    }

    int currentDigit = num % 10;
    int count = keyboard[currentDigit].size();

    for (int i = 0; i < count; ++i) {
        helper(num / 10, keyboard, keyboard[currentDigit][i] + output);
    }
}

void printKeypad(int num){
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

    helper(num, keyboard);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
