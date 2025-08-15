// Leetcode 1636
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
typedef pair<int, int> pi;
// For this, If multiple values have the same frequency, sort them in decreasing order.
// We need to define a comparator and replace greater<pi> with comparator
struct cmp {
    bool operator()(pi& a, pi& b) {
        if (a.first == b.first)
            return a.second < b.second; // higher value first when freq equal
        return a.first > b.first; // lower frequency first
    }
};
vector<int> frequencySort(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int , int> mp;
    // map pair is <element, frequency>
    for(int i = 0;i<n;i++){
        mp[nums[i]]++;
    }
    priority_queue<pi, vector<pi>, cmp> pq;
    // heap pair is <frequency, element>
    for(auto x : mp){
        int ele = x.first;
        int freq = x.second;
        pair<int,int> p = {freq, ele};
        pq.push(p);
        // or we can write directly pq.push({x.second, x.first});
    }
    while(pq.size() > 0){
        int f = pq.top().first;
        int e = pq.top().second;
        for(int i = 0;i<f;i++){
            ans.push_back(e);
        }
        pq.pop();
    }
    return ans;
}
int main(){
    
    return 0;
}