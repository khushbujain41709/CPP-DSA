// Leetcode 703
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Time Complexity: O(NlogN)
// Space Complexity: O(K)
class KthLargest {
public:
    int heapSize;
    vector<int> scores;
    priority_queue<int, vector<int> , greater<int> > pq;
    KthLargest(int k, vector<int>& nums) {
        heapSize = k;
        scores = nums;
        for(int i = 0;i<scores.size();i++){
            pq.push(scores[i]);
            if(pq.size() > heapSize){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > heapSize) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main(){
    
    return 0;
}