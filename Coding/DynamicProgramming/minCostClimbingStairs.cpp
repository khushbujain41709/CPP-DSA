// Leetcode 746
// This is Dynamic Programming question not a greedy question.
#include<iostream>
#include<vector>
using namespace std;

// Recursion + Memoization code
// dp[i] = minimum cost to reach ith stair
int helper(vector<int>& cost, int i , vector<int>& dp){
    if(i == 1 || i == 0) return cost[i];
    if(dp[i] != -1) return dp[i];
    return dp[i] = cost[i] + min(helper(cost, i-1 , dp), helper(cost , i-2 , dp));
}
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n , -1);
    return min(helper(cost, n-1, dp), helper(cost , n-2 , dp));
}

// Tabulation
// mincost = min(arr[n-1] , arr[n-2])
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    for(int i = 2;i<n;i++){
        cost[i] += min(cost[i-1] , cost[i-2]);
    }
    return min(cost[n-1] , cost[n-2]);
}

int main(){
    
    return 0;
}