// Leetcode 1046
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int lastStoneWeight(vector<int>& stones) {
    int n = stones.size();
    priority_queue<int> pq; 
    for(int i = 0;i<n;i++){   // O(n*logn)
        pq.push(stones[i]);
    }
    while(pq.size() > 1){   // O(n*logn)
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if( x != y ){
            pq.push(y - x);
        }
    }
    if(pq.size() == 0) return 0;
    else{
        return pq.top();
    }
}
int main(){
    
    return 0;
}