// Leetcode - 239
#include<bits/stdc++.h>
using namespace std;

// method 1 whose TC - O(n*k) uses brute force that is two for loops but gives time limit exceeded, so using sliding window approach.

// method 2 - using stacks and sliding window, TC = O(n)
vector<int> ngi(vector<int> &v){
    int n = v.size();
    vector<int> output(n);  // intialize with -1
    output[n-1] = n;
    stack<int> st;  // stores indices
    st.push(n-1);  // store 0 index for initialisation
    for(int i = n-2 ; i>= 0 ;i--){
        while(st.size() > 0 && v[i] >= v[st.top()]){     
            st.pop();
        }
        if(st.size() == 0){
            output[i] = n;
        }
        else{
            output[i] = st.top();
        }
        st.push(i);
    }
    return output;
}
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    if(k == 1) return nums;
    int n = nums.size();
    // calculating ngi (next greater index) array
    stack<int> st;
    vector<int> ngIndex = ngi(nums);
    vector<int> ans;
    int j = 0;
    for(int i = 0; i <= n - k; i++){
        if(j < i) j = i;  // sometimes window slides but j does not get incremented
        while(ngIndex[j] < i + k){
            j = ngIndex[j];
        }
        ans.push_back(nums[j]);
    }
    return ans;
}
int main(){
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(v,k);
    for(int i = 0;i< ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}