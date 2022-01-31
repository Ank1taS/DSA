#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y)
{
    // Write your code here .
        int dp[n + 1]; 
  
    // Initial values 
    dp[0] = false; 
    dp[1] = true; 
  
    // Computing other values. 
    for (int i = 2; i <= n; i++) { 
  
        // If A losses any of i-1 or i-x 
        // or i-y game then he will 
        // definitely win game i 
        if (i - 1 >= 0 and !dp[i - 1]) 
            dp[i] = true; 
        else if (i - x >= 0 and !dp[i - x]) 
            dp[i] = true; 
        else if (i - y >= 0 and !dp[i - y]) 
            dp[i] = true; 
  
        // Else A loses game. 
        else
            dp[i] = false; 
    } 
  
    // If dp[n] is true then A will 
    // game otherwise  he losses 
    string s="Whis";
    if (dp[n])
    {
        s="Beerus";
        return s;
    }
    else return s;
}


int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}