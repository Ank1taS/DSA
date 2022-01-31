#include <iostream>
using namespace std;

#include <bits/stdc++.h>

int f(vector<vector <int> > &dp,int *p,int s,int e){
    if(e-s==1)
        return 0;
    
    if(dp[s][e])
        return dp[s][e];
    
    int ans=INT_MAX;
    for(int k=s+1;k<e;k++){
        int temp=f(dp,p,s,k)+f(dp,p,k,e)+p[s]*p[k]*p[e];
        ans=min(ans,temp);
    }
    dp[s][e]=ans;
    return ans;
}

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
        vector <vector <int> > dp(n+1,vector<int>(n+1,0));
    int ans=f(dp,arr,0,n);
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}