// Leetcode 213
#include<iostream>
#include<vector>
using namespace std;
// [2,7,9,3,1] must give 11 as 2, 9, 1 can't be robbed together.
int rob(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
    if(n == 3) return max(nums[1] , max(nums[0], nums[2]));

    // For dp (1 to n-1)
    vector<int> dp(n);
    dp[n-1] = nums[n-1];  // dp is of size n then first element is uninitialized. Leave it.
    dp[n-2] = max(nums[n-1], nums[n-2]);
    for(int i = n-3;i>= 1;i--){
        dp[i] = max(dp[i+1], nums[i] + dp[i+2]);  // final dp content is : __, 10, 10, 3, 1
    }

    // For dp2 (0 to n-2)
    vector<int> dp2(n);
    dp2[n-2] = nums[n-2];  // dp2 is of size n then last element is uninitialized. Leave it.
    dp2[n-3] = max(nums[n-3], nums[n-2]);
    for(int i = n-4;i>= 0;i--){
        dp2[i] = max(dp2[i+1], nums[i] + dp2[i+2]);  // final dp content is : 11, 10, 9, 3, __
    }

    return max(dp[1] , dp2[0]);
}
int main(){
    
    return 0;
}