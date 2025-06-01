// Leetcode 1493
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// methos 1 TC = O(n), same code as maxConsecutiveOnesIII Leetcode 1004, just set k = 1 and return maxLen - 1 as we delete one Element here(virtually).
int longestSubarray(vector<int>& nums){
    int flips = 0;
    int k = 1;
    int n = nums.size();
    int i = 0;
    int j = 0;
    int maxLen = INT_MIN;
    int len = 0;
    while(j < n){
        if(nums[j] == 1) j++;
        else{  // nums[j] == 0
            if(flips < k){
                flips ++;
                j++;
            }
            else{ // flips == k
                // i ko just uske aage vale zero se ek index aage le jao.
                len = j - i;
                maxLen = max(maxLen , len);
                while(nums[i] == 1) i++;
                i++;
                j++;
            }
        }
    }
    // when j == n then calculate last window length if it is of the max length 
    len = j - i;
    maxLen = max(maxLen , len);
    return maxLen - 1;
}

// method 2 (more efficient)
int longestSubarray(vector<int>& nums) {
    int i = 0;
    int j = 0;
    int count = 0;
    int maxLen = 0;
    int n = nums.size();
    int ZeroPos = -1;  // stores current zero position
    int prevZero = -1; // // stores index of previous zero, so need of using while loop for finding first zero.
    while(j < n){
        prevZero = ZeroPos; 
        if(nums[j] == 0){
            ZeroPos = j;
            count ++;
        }
        if(count <= 1) j++;
        else{  // when count is greater than 1 that is when window has 2 zeros
            maxLen = max(maxLen , j - i);
            i = prevZero + 1;  // imp, i ko just uske aage vale zero se ek index aage le jao.
            count --;  // as count should be less than or equal to 1 as it is increased
            j++;
        }
    }
    maxLen = max(maxLen , j - i);
    // when j == n then calculate last window length if it is of the max length 
    return maxLen - 1;
}
int main(){
    return 0;
}