#include <iostream>
using namespace std;

int lcs_DP(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];

	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}

	// Fill 1st row
	for(int j = 0; j <= n; j++) {
		output[0][j] = 0;
	}

	// Fill 1st col
	for(int i = 1; i <= m; i++) {
		output[i][0] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			// Check if 1st char matches
			if(s[m-i] == t[n-j]) {
				output[i][j] = 1 + output[i-1][j-1];
			}
			else {
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = max(a, max(b, c));
			}
		}
	}

	int result {output[m][n]};
	for (int i {0}; i <= m; ++i) {
        delete[] output[i];
    }

	return result;
}


int main() {
	string s, t;
	cin >> s >> t;

	cout << lcs_DP(s, t) << endl;
	
}
