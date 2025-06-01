// Leetcode 1004
// Concept - Unflip the first zero when any window size is calculated that is "i" ko first zero k aage le aao aur vha se new window start kro. 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int longestOnes(vector<int>& nums, int k){
    int flips = 0;
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
    return maxLen;
}
int main(){
    vector<int> v = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout<<longestOnes(v,k);
    return 0;
}