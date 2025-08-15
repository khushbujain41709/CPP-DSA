// Leetcode 509
// We have solved it in 4 ways - Recursive code, recursive code with memoization, tabulation iterative code, iterative code with space optimization.
// One more approach is there in which we can solve fibonaaci in O(1) time - Binary Exponentiation.
#include<iostream>
#include<vector>
using namespace std;

// Using Recursion 
// TC = O(2^n) as Height of the tree = n
// Number of nodes(number of operations) = 2^n 
// SC = O(n) which is call stack space
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1)+fib(n-2);
}

// Using Memoization - Top Down DP 
// TC = O(2*n) = O(n)
// SC = O(n)(EXtra Array) + O(n)(Call Stack)
// Make a vector of size n+1 and stores values from 2 to n
int helper(int n , vector<int>& dp){
    if (n <= 1) return n;
    if(dp[n] != -1){  // dp[n] mei kuch store hai
        return dp[n];
    }
    // agar dp[n] kuch store nahi hai toh calculate krke store kro
    dp[n] = helper(n-1 , dp)+ helper(n-2 , dp);
    return dp[n];
}
int fib(int n){
    vector<int> dp(n+1 , -1);
    return helper(n, dp);
}

// Using Tabulation
// TC = O(n)
// SC = O(n)(EXtra Array)
int fib(int n){
    if(n <= 1) return n;
    vector<int> dp(n+1);
    for(int i = 0; i<= n ;i++){
        if(i <= 1) dp[i] = i;
        else dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// With Space Optimization
int fib(int n){
    if(n <= 1) return n;
    vector<int> dp(3);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 1; i<= n-1 ;i++){
        dp[2] = dp[1] + dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}
int main(){
    
    return 0;
}