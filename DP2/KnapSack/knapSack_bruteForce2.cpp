#include <iostream>
using namespace std;


int knapsack(int *weights, int *values, int n, int maxWeight) {
// Base case
	if(n == 0 || maxWeight == 0) {
		return 0;
	}

	if(weights[0] > maxWeight) {
		return knapsack(weights + 1, values + 1, n - 1, maxWeight);
	}

	// Recursive calls
	int x = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
	int y = knapsack(weights + 1, values + 1, n - 1, maxWeight);

	return max(x, y);
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