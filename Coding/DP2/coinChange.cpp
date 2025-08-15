// CSES Problem - Minimizing Coin
// Letcode 322
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// Method 1 (Easy) Do this
vector<vector<int>> dp;
int helper(int idx, vector<int>& coins, int amount){
    int n = coins.size();
    if(idx == n){
        if(amount == 0) return 0;
        else return INT_MAX;  // no valid answer;
    }
    if(dp[idx][amount] != -1) return dp[idx][amount];
    if(amount - coins[idx] < 0) return dp[idx][amount] = helper(idx+1, coins, amount); /// leave
    long long take = 1LL + helper(idx, coins, amount - coins[idx]); 
    // idx not idx +1 as infinite coins can be used
    long long leave = helper(idx+1, coins, amount);
    return dp[idx][amount] = min(take, leave);
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    // idx = 0 to n-1 and amount = 0 to amount
    dp.resize(n, vector<int>(amount + 1 , -1));
        int ans =  helper(0, coins, amount);
    if(ans == INT_MAX) return -1;
    else return ans;
}

// Method 2
int helper(vector<int>& coins, int amount, vector<int>& dp){
    if(amount == 0) return 0;
    int n = coins.size();
    int res = INT_MAX;
    if(dp[amount] != -1) return dp[amount];
    for(int i = 0;i<n;i++){
        if(amount - coins[i] < 0) continue;
        res = min(res, helper(coins, amount - coins[i], dp));
    }
    if(res == INT_MAX) return dp[amount] = INT_MAX;
    return dp[amount] = res + 1;
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount+1, -1);
    int ans =  helper(coins, amount, dp);
    if(ans == INT_MAX) return -1;
    else return ans;
}
int main(){
    int n, amount;
    cin>> n >> amount;
    vector<int> coins;
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        coins.push_back(x);
    }
    cout<<coinChange(coins,amount);
    return 0;
}