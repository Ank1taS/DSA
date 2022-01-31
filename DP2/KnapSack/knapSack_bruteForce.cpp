#include <iostream>
using namespace std;

int knapsack(int *weights, int *values, int endIndex, int maxWeight, int currentIndex) {
	// base case
    if (currentIndex == endIndex) {
        return 0;
    }

    int result1 {0};
    // recursive call - with considering current index value only if currentIndex weight is less or equals to the maxWeight
    if(weights[currentIndex] > maxWeight) {
        result1 = values[currentIndex] + knapsack(weights, values, endIndex, maxWeight - weights[currentIndex], currentIndex + 1);
    }

    // recursive call - without considering current index value
    int result2 = knapsack(weights, values, endIndex, maxWeight, currentIndex + 1);
    
    int finalResult {max(result1, result2)};

    return finalResult;
}

int knapsack(int *weights, int *values, int n, int maxWeight) {
    return knapsack(weights, values, n, maxWeight, 0);
}


int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}