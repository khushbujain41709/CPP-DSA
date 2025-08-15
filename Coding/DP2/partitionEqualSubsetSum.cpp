// Leetcode 416
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dp;
bool helper(vector<int>& nums, int target, int idx , int sum){
    int n = nums.size();
    if(idx == n){
        if(sum == target) return true; 
        else return false;
    }
    if(dp[idx][sum] != -1) return dp[idx][sum];
    if(sum == target) return dp[idx][sum] = true; // agar end tak aane se pehle sum target k equal ho jaye
    if(sum + nums[idx] > target) return dp[idx][sum] = helper(nums, target, idx + 1, sum);
    bool take = helper(nums, target, idx + 1, sum + nums[idx]);
    bool leave = helper(nums, target, idx + 1, sum);
    return dp[idx][sum] = take || leave;
}
bool canPartition(vector<int>& nums) {
    int target = 0;
    int n = nums.size();
    for(int i = 0; i< n; i++){
        target += nums[i];
    }
    if(target % 2 != 0) return false;
    target /= 2;
    dp.clear();
    // idx from 0 to n-1 and sum from 0 to target 
    dp.resize(n, vector<int> (target + 1, -1));
    return helper(nums, target, 0, 0);
}
int main(){
    
    return 0;
}