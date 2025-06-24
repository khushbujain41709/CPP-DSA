// Leetcode - 53 but gives tle ...
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// Using brute force
int maxSubArray0(vector<int>& nums , int k){
    int n = nums.size();
    int maxSum = INT_MIN;
    int maxIndex = -1;
    for(int i = 0;i<n-k+1;i++){  // O(n-k+1)
        int sum = 0;
        for(int j = i;j<i+k;j++){  // O(k)
            sum += nums[j];
            if(sum >= maxSum){
                maxSum = sum;
                maxIndex = i;
            }
        }
    } 
    return maxSum;
    // TC = O(n*k)  where k can be large so it is not a constant
}

// Sliding Window for leetcode but gives tle
// current window sum = previous window sum + last element of current window(arr[j]) - first element of previous window(arr[i-1])
int maxSubArray2(vector<int>& nums , int k){
    int n = nums.size();
    int maxSum = INT_MIN;
    int maxIndex = 0;
    int prevSum = 0;
    for(int i = 0;i<k;i++){  // O(k)
        prevSum += nums[i];
    }
    maxSum = prevSum; // imp
    int i = 1;
    int j = k;
    while(j<n){  // O(n-k)
        int currSum = prevSum + nums[j] - nums[i-1];
        if(currSum >= maxSum){
            maxSum = currSum;
            maxIndex = i;
        }
        prevSum = currSum;
        i++;
        j++;
    } 
    // TC = O(n)
    return maxSum;
}
int maxSubArray(vector<int>& nums){
    int ans = INT_MIN;
    int n = nums.size();
    for(int i = 1;i<n+1;i++){
        int sum = maxSubArray2(nums,i);
        if(sum >= ans){
            ans = sum;
        }
    }
    return ans;
}

int main(){
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = INT_MIN;
    for(int i = 1;i<v.size()+1;i++){
        int sum = maxSubArray0(v,i);
        if(sum >= ans){
            ans = sum;
        }
    }
    cout<<ans;
}