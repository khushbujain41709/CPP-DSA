// Leetcode 378
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int kthSmallest(vector<vector<int>>& matrix, int k){
    // TC = O(m*n * log k) but can be solved in O(k^2* log k)
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    priority_queue<int> maxHeap;
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            maxHeap.push(matrix[r][c]);
            if (maxHeap.size() > k) maxHeap.pop();
        }
    }
    return maxHeap.top();
}
int main(){
    
    return 0;
}