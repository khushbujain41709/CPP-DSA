// Leetcode 560
// see constraints, array element can be negative
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// approach 1 :
// make a prefix sum array, for eaxmple let input be [3,2,4,5,2,8,1,2,7] and k = 9
// now prefix sum array is : [3,5,9,14,16,24,25,27,34]
// now answer is 4 as [3,2,4], [4,5] , [8,1] , [2,7] 
// so we traverse in whole prefix sum array and check if arr[i] - k is present in elements before arr[i] , if yes then count++;
// Searching can be done using binary search as it is prefix sum array is always sorted.
// Suppose let arr[i] = 25 then 25 - 9 = 16 and 16 is present in earlier array then count++;
// TC = O(n*log n)

// approach 2
// Same concept, just use map for searching
// imp test cases
// run testcase {1,-1,0} and k = 0
// run testcase {0,0,0,0} and k = 0 -> this will show why to use map instead of set
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    for(int i = 1;i<n;i++){
        nums[i] = nums[i-1] + nums[i];
    }
    int count = 0;
    unordered_map<int , int> m;
    for(int i = 0;i<n;i++){
        int target = nums[i] - k;
        if(nums[i] == k){
            count++;
        }
        if(m.find(target) != m.end()){  
            count += m[target];  // add frequency in count
        }
        m[nums[i]]++;
    }
    return count;
}
int main(){
    
    return 0;
}