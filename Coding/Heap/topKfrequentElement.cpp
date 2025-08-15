// Leetcode 347
// using minHeap with pair. Here if we push and pop elements from minheap, it uses its first element of pair.
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef pair<int, int> pi;
vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    // map pair is <element, frequency>
    for(int i = 0; i< n;i++){
        mp[nums[i]]++;
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    // heap pair is <frequency, element>
    for(auto x : mp){
        int ele = x.first;
        int freq = x.second;
        pair<int,int> p = {freq, ele};
        pq.push(p);
        // or we can write directly pq.push({x.second, x.first});
        if(pq.size() > k) pq.pop();
    }
    while(pq.size() > 0){
        int ele = pq.top().second;
        ans.push_back(ele);
        pq.pop();
    }
    return ans;
}
int main(){
    
    return 0;
}