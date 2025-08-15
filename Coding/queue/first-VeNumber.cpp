// First negative in window of size K
// same question in stack and sliding window
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int> v = {12,1,3,-4,-1,2,1,-5,4};  
    // size = 9 and if k = 3 then n - k + 1 = 7 is elements in ans array
    int n = v.size();
    int k = 3;
    queue<int> q;
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(v[i] < 0){
            q.push(i);
        }
    }
    int i = 0;
    while( i <= n-k){
        while(q.size() > 0 && q.front() < i){
            q.pop();
        }
        if(q.size() == 0 || q.front() >= i+k) ans.push_back(0);
        else{
            ans.push_back(v[q.front()]);
        }
        i++;
    }
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}