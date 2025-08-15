// Leetcode 1137
#include<iostream>
#include<vector>
using namespace std;
// Using Memoization
int helper(int n , vector<int>& dp){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = helper(n-1, dp) + helper(n-2, dp) + helper(n-3, dp);
}
int tribonacci(int n) {
    vector<int> dp(n+1, -1);
    return helper(n, dp);
}

// Using Tabulation
int tribonacci(int n) {
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
        vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3 ; i <=n ;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

// With Space Optimization
int tribonacci(int n){
    if(n <= 1) return n;
    vector<int> dp(4);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i<= n ;i++){
        dp[3] = dp[1] + dp[0] + dp[2];
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[3];
    }
    return dp[3];
}
int main(){
    
    return 0;
}