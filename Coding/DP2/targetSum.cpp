// Leetcode 494
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<vector<int>> dp;
int total;
unordered_map<int, vector<int>> mp; // instead of 2D DP we can also use map
int helper(int idx, vector<int>&nums, int sum, int target){
    int n = nums.size();
    if(idx == n){
        if(sum == target) return 1;
        else return 0;
    }
    if(dp[idx][sum + total] != -1) return dp[idx][sum + total];
    int add = helper(idx + 1, nums, sum + nums[idx] , target);
    int sub = helper(idx + 1, nums, sum - nums[idx] , target);
    return dp[idx][sum + total] = add + sub;
}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    total = 0;
    // i = 0 to n-1 and sum = -total to +total = 2*total + 1
    // sum = 0 to 2*total 
    // now for original value of target we add total to it as -total + total = 0 and total + total = 2*total
    // nums = [1,1,1,1,1], target = 3, here total = 5 and 2*total + 1 = 11
    // so dp will be of 5 rows and 10 columns
    // sum = -5 will be stored in -5+5 = column 0 
    // sum = 5 will be stored in 5+5 = column 10 
    // sum = -3 will be stored in -3+5 = column 2 
    // sum = 3 will be stored in 3+5 = column 8 
    for(int i = 0;i<n;i++){
        total += nums[i];
    }
    dp.resize(n, vector<int> (2*total + 1, -1));
    return helper(0, nums, 0, target);
}
int main(){
    
    return 0;
}