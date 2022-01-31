#include <iostream>
using namespace std;

#include <bits/stdc++.h>

int helper(int x,int n,int curNo,int *dp){
    if(x<0){
        return 0;
    }
    if(x==0){
        return 1;
    }

    int ans=0;

    for(int i=curNo;pow(i,n)<=x;i++){
            ans+=helper(x-pow(i,n),n,i+1,dp);
    }
    dp[x]=ans;
    return ans;    
}

int getAllWays(int a, int b) {
    // Write your code here
        int dp[100000];
    for(int i=0;i<100000;i++){
        dp[i]=-1;
    }
    return helper(a,b,1,dp);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}