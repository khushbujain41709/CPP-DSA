// Leetcode 786
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// making maxheap
// Time Complexity: O(N^2)
// Space Complexity: O(Total Pairs)
typedef pair<float, pair<int, int>> fp;
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k){
    int n = arr.size();
    priority_queue<fp> pq;
    for(int i = 0; i<n-1; i++){
        for(int j =  i+1; j<n; j++){
            pq.push({(float)arr[i]/arr[j], {arr[i], arr[j]}});
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    vector<int> ans;
    ans.push_back(pq.top().second.first);
    ans.push_back(pq.top().second.second);
    return ans;
}
int main(){
    
    return 0;
}