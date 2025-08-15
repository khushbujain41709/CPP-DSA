// Leetcode 658
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> pi;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    priority_queue<pi> pq;
    vector<int> ans;
    for(int i = 0 ; i< arr.size();i++){
        pq.push( { abs(x - arr[i]) , arr[i] } );
        if(pq.size() > k) pq.pop();
    }
    while(pq.size() > 0){
        int ele = pq.top().second;
        ans.push_back(ele);
        pq.pop();
    }
    sort(ans.begin() , ans.end());
    return ans;
}
int main(){
    
    return 0;
}