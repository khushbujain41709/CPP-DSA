// GFG
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minCost(vector<int>& arr){
    int n = arr.size();
    priority_queue<int , vector<int> , greater<int>> pq;
    for(int i = 0 ;i< n;i++){
        pq.push(arr[i]);
    }
    int cost = 0;
    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        int sum = x+y;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}
int main(){
    return 0;
}