// Leetcode 209
// Using brute force TC = O(n^2)
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// TC = O(n) as both i and j traverse in whole array in linear time and total number of operations is less than 2*n
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    int len = 0;
    int minLen = INT_MAX;
    int sum = 0;
    while(j<n){
        sum += nums[j];
        while(sum >= target){
            len = j - i + 1;
            minLen = min(len, minLen);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    if(minLen == INT_MAX) return 0;
    else return minLen;
}
int main(){
    
    return 0;
}