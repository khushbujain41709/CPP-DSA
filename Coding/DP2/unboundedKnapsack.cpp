#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dp;
int helper(int W, vector<int> &val, vector<int> &wt, int i, int curr_weight){
    // i is index
    int n = val.size();
    if(i == n) return 0;
    if(dp[i][curr_weight] != -1) return dp[i][curr_weight];
    if(curr_weight + wt[i] > W){ // if exceeds capacity then make leave call
        return dp[i][curr_weight] = helper(W, val, wt, i+1, curr_weight);
    }
    int take = val[i] + helper(W, val, wt, i, curr_weight + wt[i]);  // just do i in place of i + 1 in 0/1 knapsack
    int leave = helper(W, val, wt, i+1, curr_weight);
    return dp[i][curr_weight] = max(take, leave);
}
int knapsack(int W, vector<int> &val, vector<int> &wt){
    // W is capacity
    // i from 0 to n-1 and W from 0 to W
    int n = val.size();
    dp.clear();
    dp.resize(n, vector<int>((W+1), -1)); 
    // i and curr_weight are state of DP as they are changing
    return helper(W, val, wt,0,0);
}
int main(){
    
    return 0;
}