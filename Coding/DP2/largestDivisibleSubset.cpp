// Leetcode 368
// We will sort the array so if nums[i] % nums[j] == 0 then nums[j] % nums[i] != 0
// We then need to create a dp array where dp[i] stores the longest subset upto this index.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums){
    int n = nums.size();
    // Let nums be 1 3 4 6 8 12 13
    // if a%b == 0 and b%c == 0 then a%c == 0
    /*
    for example : nums be  : 1  2 4 8
                    dp be    : 1  2 3 4
                    prrev be : -1 0 1 2
    Start at index 3 (nums[3] = 8)
    → prev[3] = 2 → nums[2] = 4  
    → prev[2] = 1 → nums[1] = 2  
    → prev[1] = 0 → nums[0] = 1  
    → prev[0] = -1 → stop
    */
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    sort(nums.begin() , nums.end());
    int mx = 0;
    for(int i = 1; i<n ;i++){
        for(int j = 0; j<i ;j++){
            if(nums[i] % nums[j] == 0  && dp[i] < dp[j] + 1){  
            // imp condition dp[i] < dp[j] + 1
            // since we have sorted the array already so if nums[i] % nums[j] == 0 then nums[j] % nums[i] != 0
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if(dp[mx] < dp[i]){
            mx = i;
        }
    }
    vector<int> res;
    for (int i = mx; i >= 0; i = prev[i]){
        res.push_back(nums[i]);
    }
    return res;
}
int main(){
    
    return 0;
}