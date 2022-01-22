#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    if (k >= n) {
        return 0;
    }

    int timeDuration {0};

    // max-priority queue to store elements of arr in sorted order
    priority_queue<int> elementPQ;

    // queue to store indices of arr
    queue<int> indexQ;

    for (int i {0}; i < n; ++i) {
        indexQ.push(i);
        elementPQ.push(arr[i]);
    }

    while (elementPQ.empty() == false) {
        if (elementPQ.top() == arr[indexQ.front()]) {
            ++timeDuration;
            if (indexQ.front() == k) {
                return timeDuration;
            }
            else {
                elementPQ.pop();
                indexQ.pop();
            }
        }
        else {
            int temp {indexQ.front()};
            indexQ.pop();
            indexQ.push(temp);
        }
    }

}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}