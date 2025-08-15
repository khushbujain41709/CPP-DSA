// Leetcode 70
#include<iostream>
#include<vector>
using namespace std;
// Using Memoization
int helper(int n , vector<int>& dp){
    if(n == 0 || n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = helper(n-1, dp) + helper(n-2, dp);
}
int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return helper(n, dp);
}

// Using Tabulation
int climbStairs(int n){
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2 ; i <=n ;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    
    return 0;
}