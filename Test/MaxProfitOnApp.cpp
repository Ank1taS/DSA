#include <iostream>
using namespace std;
// #include "solution.h"

int maximumProfit(int budget[], int n) {
    // Write your code here
    int profit {0};
    int costumer {0};

    int *profitArr = new int[n];

    for (int i {0}; i < n, ++i) {
        int currentBuget = budget[i];
        
        for (int j {0}; j < n; ++j) {
            if (currentBuget <= budget[j]) {
                ++costumer;
            }
        }

        profitArr[i] = costumer * currentBuget;
        costumer = 0;
    }

    sort(profitArr, profitArr + n);
    profit = profitArr[n - 1];
    delete[] profitArr;
    
    return profit;
}


int main() {
    int n, *input, i, *cost;
    cin >> n;

    input = new int[n];
    
    for(i = 0; i < n; i++)
        cin >> input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
