// Leetcode 973
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int , vector<int> > pi;
vector<vector<int>> kClosest(vector<vector<int>>& point, int k) {
    // we can make heap < int , pair<int, int> > or heap < int , vector<int> >
    int n = point.size();
    priority_queue<pi> pq;
    vector<vector<int>> ans;
    for(int i = 0 ; i< point.size();i++){
        int distance = point[i][0]* point[i][0] + point[i][1]* point[i][1];
        pq.push( { distance, point[i] } );
        if(pq.size() > k) pq.pop();
    }
    while(pq.size() > 0){
        vector<int> ele = pq.top().second;
        ans.push_back(ele);
        pq.pop();
    }
    return ans;
}
int main(){
    
    return 0;
}