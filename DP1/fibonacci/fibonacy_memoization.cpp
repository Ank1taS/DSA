#include <iostream>
using namespace std;

int fibo_helper(int n, int *ans) {
	if(n <= 1) {
		return n;
	}

	// Check if output already exists
	if(ans[n] != -1) {
		return ans[n];
	}

	// Calculate output
	int a = fibo_helper(n-1, ans);
	int b = fibo_helper(n-2, ans);

	// Save the output for future use
	ans[n] = a + b;
	
	// Return the final output
	return ans[n];
}

int fibo_2(int n) {
	int *ans = new int[n+1];

	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	
	return fibo_helper(n, ans);
}

int main() {
	int n;
	cin >> n;
	cout << fibo_2(n) << endl;
}
