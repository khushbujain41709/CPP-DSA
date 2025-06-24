// Sort a nearly sorted array - Sort a K sorted array
// Here, we need to sort an array in ascending order from min to max, so we need the minimum element at every point of time.
// So we will use minHeap
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int> v = {6,5,3,2,8,10,9};
    int k = 3;
    int n = v.size();
    priority_queue<int , vector<int> , greater<int>> pq;
    vector<int> ans;
    for(int i = 0;i < n; i++){
        pq.push(v[i]);
        if(pq.size() > k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while(pq.size() > 0){
        ans.push_back(pq.top());
        pq.pop();
    }
    for(int i = 0 ; i< n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}