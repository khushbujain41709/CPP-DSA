// LEETCODE 2419
// Find the length of longest subarray which has maximum possible bitwise AND value.
// x & y if(x > y) gives a value smaller than x always.
// x & x = x
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int count = 0;
    int maxElem = *max_element(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
        if(nums[i] == maxElem){
            count++;
            ans = max(ans, count);
        } 
        else {
            count = 0; // reset when encountering smaller element
        }
    }
    return ans;
}
int main(){

    return 0;
}