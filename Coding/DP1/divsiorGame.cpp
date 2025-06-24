// Leetcode 1025
#include<iostream>
#include<vector>
using namespace std;
bool helper(vector<int>& dp , int n){
    if(n == 1) return false; // alice cannot paly as 1 < 1 is not possible
    if(n == 2) return true; // true means win
    if(dp[n] != -1) return dp[n];
    for(int i = 1 ; i<n; i++){
        if(n % i == 0){
            if( !helper(dp, n - i)) return dp[n] = true;
        }
    }
    return dp[n] = false; // otherwise lose
}
bool divisorGame(int n) {
    vector<int> dp(n + 1, -1);
    return helper(dp, n);
}

// method 2
bool helper(vector<int>& dp , int n){
    if(n == 1) return false;
    if(n == 2) return true; // true means win
    bool ans = true;
    if(dp[n] != -1) return dp[n];
    for(int i = 1 ; i<n; i++){
        if(n % i == 0){
            ans = ans && helper(dp , n-i);
        }
    }
    return dp[n] = !ans;
}
bool divisorGame(int n) {
    vector<int> dp(n+1 , -1);
    return helper(dp, n);
}
int main(){
    
    return 0;
}