// Leetcode 215
// TC = O(n* logk)
// SC= O(k) extra space
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int findKthLargest(vector<int>& nums, int k){
    int n = nums.size();
    priority_queue<int , vector<int>, greater<int>> pq;
    for(int i = 0; i< n; i++){
        pq.push(nums[i]);
        if(pq.size() > k) pq.pop();
    }
    return pq.top();
}
int main(){
    
    return 0;
}