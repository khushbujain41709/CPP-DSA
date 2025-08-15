// Leetcode 2044
#include<bits/stdc++.h>
using namespace std;
void generateSubset(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int> empty){
    int n = nums.size();
    if(idx == n){
        ans.push_back(empty);
        return;
    }
    generateSubset(nums, ans, idx+1 , empty);
    empty.push_back(nums[idx]);
    generateSubset(nums, ans, idx+1 , empty);
}
int calculateBitOr(vector<int>& a){
    int n = a.size();
    int bitOr = 0;
    for(int i = 0; i<n ; i++){
        bitOr = a[i] | bitOr;
    }
    return bitOr;
}
int countMaxOrSubsets(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> subset; 
    generateSubset(nums, subset, 0, {});
    int maxBitOr = 0;
    for(int i = 0; i<n ; i++){
        maxBitOr = nums[i] | maxBitOr;
    }
    int count = 0;
    for(int i = 0; i< subset.size(); i++){
        if(!subset[i].empty()){
            if(calculateBitOr(subset[i]) == maxBitOr){
                count++;
            }
        }
    }
    return count;
}
int main(){
    
    return 0;
}