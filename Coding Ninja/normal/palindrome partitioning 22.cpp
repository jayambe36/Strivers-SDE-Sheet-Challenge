#include <bits/stdc++.h> 
bool isPalindrome(string s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;j--;
    }
    return true;
}
int palindromePartitioning(string s) {
    int n = s.length();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // dp[i][j] = min number of partitions for substring s{i..j}
    for(int gap = 1; gap<n; gap++){
        for(int i = 0; i+gap<n ;i++){
            int j = i+gap;
            if(isPalindrome(s,i,j)){
                dp[i][j] = 0;
            }else{
                dp[i][j] = INT_MAX;
                for(int k = i; k<j;k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
                }
            }
        }
    }
    return dp[0][n-1];
}