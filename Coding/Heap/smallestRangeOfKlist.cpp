// Leetcode 632
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
// Loop ends when pointer goes out of bound oa any onr array as I have to include one element of each array
// We make a minHeap and pop one element from minHeap and increment the pointer of the popped element.  
// TC = O(nk* log k) where k lists each of size n on an average and nk is total number of elements in nums
using namespace std;
typedef pair<int , pair<int, int>> pip;
    // {num , {row, col}}
vector<int> smallestRange(vector<vector<int>>& nums){
    int k = nums.size(); // heap size
    priority_queue<pip , vector<pip> , greater<pip>> pq; 
    int maxx = INT_MIN;  // maintaining an maximum element of the heap
    for(int i = 0;i< k;i++){  // TC = O(k* log k)
        pq.push({nums[i][0], {i , 0}});   // insert all rows first element in heap
        maxx = max( maxx , nums[i][0] );
    }
    // For range [a,b]- let a be minHeap top and b be maxx. We will update it.
    int range = maxx - pq.top().first;
    int start = pq.top().first;
    int end = maxx;
    while(true){ // TC = O(nk* log k)
        // pop minHeap top element - mimimum element and increment pointer
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        if(col == nums[row].size()-1) break; // -1 as col+1 doesnot exist
        pq.pop();
        pq.push({nums[row][col+1], {row , col+1}});
        maxx = max(maxx , nums[row][col+1] );
        int newRange = maxx - pq.top().first;
        range = min(range , newRange);
        if(range < end - start){  // agar new range choti hai, existing range se
            start = pq.top().first;
            end = maxx;
        }
    }
    return {start,end};
}
int main(){
    
    return 0;
}