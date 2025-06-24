// Leetcode 198
// See testcase [2,1,1,9] and output should be 2+9 = 11
// So approach like finding minimum of even indices sum and odd indices sum is not correct.
// Correct Approach - 
/*
                             ( [2,1,1,9] , 0 )
                loot arr[0]/                 \  don't loot arr[0]
            2 + ([2,1,1,9] , 2)               ( [2,1,1,9] , 1 )
            /               \                 /                \ 
    2+1+([2,1,1,9],4)    2+([2,1,1,9],3)    1+([2,1,1,9],3)    ([2,1,1,9],2)
           |                    |                   |                 |
           3                    11                  10                9 (loot max of 1 and 9)
*/
// State of the DP is i here , It is the set of all the parameters usinh which we can identify the overlapping subproblems uniquely.
// Number of subproblems depend on i which ranges from 0 to n-1. There will be total n unique subproblems.
#include<iostream>
#include<vector>
using namespace std;

// Using Memoization
int helper(vector<int>& nums, int i, vector<int>& dp){
    int n = nums.size();
    if(i == n-1) return nums[i];
    if(i == n-2) return max(nums[i] , nums[i+1]);
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(nums[i] + helper(nums, i+2, dp) , 0 + helper(nums, i+1, dp));
}
int rob(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return helper(nums, 0, dp);
}

// Using Tabulation
// After building recursive solution, notice the ordering of the subproblems to get answer.
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n);
    if(n == 1) return nums[0];
    dp[n-1] = nums[n-1];
    dp[n-2] = max(nums[n-1], nums[n-2]);
    for(int i = n-3;i>= 0;i--){
        dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
    }
    return dp[0];
}

// With Space Optimization
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(3);
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);;
    for(int i = 2; i<n;i++){
        dp[2] = max(dp[1], nums[i] + dp[0]);
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    return dp[2];
}
int main(){
    
    return 0;
}