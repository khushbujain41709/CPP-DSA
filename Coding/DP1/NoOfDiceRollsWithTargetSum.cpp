// Leetcode 1155
// f(n, k , target) - Number of ways to get target by die throw of n dices of faces k
// f(n,k , target) = summation of f(n-1, k, target - v) where v belongs to 1 to k  and target - v >= 0
#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std; 
int helper(int n, int k, int target, vector<vector<int>>& dp){
    // n and target are two state of variables which are changing
    // so we 2D DP
    if(n == 0 and target == 0) return 1;
    if(n == 0) return 0;  // for other cases who are not giving 1 like (0, 6, 5)
    if(dp[n][target] != -1) return dp[n][target];
    int sum = 0;
    for(int i = 1 ; i<= k; i++){
        if(target - i < 0) break;
        sum = (sum % MOD + helper(n-1, k , target - i, dp) % MOD) % MOD;
    }
    return dp[n][target] = sum % MOD;    
}
int numRollsToTarget(int n, int k, int target){
    vector<vector<int>> dp(n+1, vector<int>(target + 1 , -1));
    return helper(n, k ,target, dp);
}
int main(){
    
    return 0;
}