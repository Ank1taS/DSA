// Given a string S, remove consecutive duplicates from it recursively.

#include <iostream>
using namespace std;

int getLength(char *input) {
    if (input[0] == '\0') {
        return 0;
    }

    return 1 + getLength(input + 1);
}

void helper(char *input, int size) {
    if (size == 0) {
        return;
    }

    if (input[size - 1] == input[size]) {
        for (int i = size; input[i] != '\0'; ++i) {
            input[i] = input[i + 1];
        }
        
    }

    helper(input, size - 1);
}

void removeConsecutiveDuplicates(char *input) {
    int size = getLength(input);

    return helper(input, size);
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}
