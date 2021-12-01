// For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
// If the expression can't be balanced, return -1.
// Example:
// Expression: {{{{
// If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

// Expression: {{{
// In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.


#include <iostream>
#include <string>
#include <stack>
using namespace std;

int countBracketReversals(string input) {
	if (input.length() % 2) {
        return -1;
    }

    stack<char> st;

    for (auto &ch: input) {
        if (ch == '{') {
            st.push('{');
        }
        else if (ch == '}') {
            if (st.empty()) {
                st.push('}');
            }
            else {  // !st.empty() 
                if (st.top() == '{') {
                    st.pop();
                }
                else {  // st.top() == '}'
                    st.push('}');
                }
            }
        }
    }

    int count {0};

    if (st.empty()) {
        return count;
    }
    else {
        while (!st.empty()) {
            char ch1 = st.top();
            st.pop();
            char ch2 = st.top();
            st.pop();

            if (ch1 == ch2) {
                ++count;
            }
            else {
                count += 2;
            }
        }
    }

    return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}