// You have been given two stacks that can store integers as the data. 
// Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.


#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {

    // base case
    // if size of stack is 0 or one no need to reverse
    if (input.size() == 0 || input.size() == 1) {
        return;
    }

    // current top element is stored in a temporary varriable then poped out
    int currentTop = input.top();
    input.pop();

    // recursive call
    reverseStack(input, extra);

    // push every element to extra and pop it from input one by one
    while(!input.empty()) {
        extra.push(input.top());
        input.pop();
    }

    // push extracted temporary varriable value to the buttom of stack
    input.push(currentTop);

    // store element from extra to input one by one
    while(!extra.empty()) {
        input.push(extra.top());
        extra.pop();
    }    

    return;
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}