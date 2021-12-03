// For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.
// Example:
// Expression: (()())
// Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.


#include <iostream>
#include <string>
#include <stack>


bool isBalanced(std::string expression) {
    if (!expression[0]) {
        return false;
    }

    if (expression[0] == ')' || expression[0] == ']' || expression[0] == '}') {
        return false;
    }

    std::stack<char> st;

    for (auto ch : expression) {
        // checks the character is open paranthesis then push it into the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
            continue;
        }

        // if character is close parenthesis
        if (ch == ')') {
            if (st.top() == '(') {
                st.pop();
                continue;
            }
        }
        else if (ch == '}') {
            if (st.top() == '{') {
                st.pop();
                continue;
            }
        }
        else if (ch == ']') {
            if (st.top() == '[') {
                st.pop();
                continue;
            }
        }

        // if close parenthesis does not matches the stack's open paraentheis
        return false;
    } 

    if (st.empty()) {
        return true;
    }
    else {
        return false;
    }
}

int main() 
{
    std::string input;
    std::cin >> input;
    std::cout << ((isBalanced(input)) ? "true" : "false");
}
