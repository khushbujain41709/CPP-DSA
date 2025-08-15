// Leetcode 2786
#include<iostream>
#include<vector>
using namespace std;
vector<vector<long long>> dp;
long long helper(int idx, vector<int>& nums, int x, int parity){
    int n = nums.size();
    if(idx == n) return 0;
    // if we want to take
    long long take = 0;
    if(dp[idx][parity] != -1) return dp[idx][parity];
    if(nums[idx] % 2 == parity){ // 1 is passes as idx and if same parity 
        take = nums[idx] + helper(idx+1, nums, x, parity);
    }
    else{ // if different parity
        take = nums[idx] - x + helper(idx+1, nums, x, nums[idx] % 2); // parity will change
    }
    // if we want to leave
    long long leave = 0;
    leave = helper(idx+1, nums, x, parity);
    return dp[idx][parity] = max(leave, take);
}
long long maxScore(vector<int>& nums, int x){
    int n = nums.size();
    int parity = nums[0] % 2;
    // 2D DP 
    // i = 1 to n-1 and parity from 0 to 1
    dp.resize(n, vector<long long> (2, -1));
    return nums[0] + helper(1, nums, x, parity);  // add nums[0] in score
}
int main(){
    
    return 0;
}