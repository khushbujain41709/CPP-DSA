// Leetcode 496
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nge(vector<int>& nums){
    int n = nums.size();
    stack<int> st;
    st.push(nums[n-1]);
    vector<int> ans(n,-1);
    for(int i = n-2; i>= 0; i--){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nextGreater = nge(nums2);
    vector<int> ans;
    for(int i = 0;i<nums1.size();i++){
        for(int j = 0;j<nums2.size();j++){
            if(nums1[i] == nums2[j]){
                ans.push_back(nextGreater[j]);
                break;
            }
        }
    }
    return ans;
}
int main(){
    
    return 0;
}