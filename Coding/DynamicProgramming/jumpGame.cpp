// Leetcode 55
#include<iostream>
#include<vector>
using namespace std;
vector<int> dp; // if we take bool dp then it will take only 0 and 1 values but we need -1 to mark also.
bool helper(int index, vector<int>& nums){
    int n = nums.size();
    if(index >= n-1) return true;
    bool ans = false;
    if(nums[index] >= n - 1 - index) return true;  // like if nums is 3 2 10000 1 4 then for index = 2 check
    if(dp[index] != -1) return dp[index];
    for(int i = 1 ; i <= nums[index]; i++){
        ans = ans || helper(index + i , nums);
        if(ans) break;
    }
    return dp[index] = ans;
}
bool canJump(vector<int>& nums) {
    dp.resize(nums.size() , -1);
    return helper(0 , nums);
}
int main(){
    
    return 0;
}