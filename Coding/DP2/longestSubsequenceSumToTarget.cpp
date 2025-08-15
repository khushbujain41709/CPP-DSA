// Leetcode 2915
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dp;
int helper(vector<int>& nums, int target, int idx){
    int n = nums.size();
    if(target == 0){
        return 0;
    }
    if(idx >= n || target < 0) return -1005;
    if(dp[target][idx] != -1) return dp[target][idx];
    int take = 1 + helper(nums, target - nums[idx], idx+1);
    int leave = helper(nums, target, idx+1);
    return dp[target][idx] = max(take, leave);
}
int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    int n = nums.size();
    dp.resize(target + 1, vector<int> (n+1 , -1));
    int ans = helper(nums, target, 0);
    if(ans <= 0) return -1;
    else return ans;
}
int main(){
    return 0;
}