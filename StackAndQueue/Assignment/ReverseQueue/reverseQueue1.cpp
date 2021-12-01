// You have been given a queue that can store integers as the data. You are required to write a function that reverses the populated queue itself without using any other data structures.


#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &input) {
    // base case
    // if size of queue is 0 or one no need to reverse
	if (input.size() <= 1) {
        return;
    }

    // current front element is strored in a temporary varriable then poped out
    int currentFront {input.front()};
    input.pop();
    
    reverseQueue(input);

    // push the current top element at the end of reversed queue
    input.push(currentFront);
    return;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}