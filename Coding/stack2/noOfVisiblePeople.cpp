// Leetcode 1944
#include<bits/stdc++.h>
using namespace std;
vector<int> canSeePersonsCount(vector<int>& heights){
    int n = heights.size();
    stack<int> st;
    st.push(heights[n-1]);
    vector<int> see(n);
    see[n-1] = 0;
    for(int i = n-2;i>=0;i--){
        int count = 0;
        while(!st.empty() && st.top() <= heights[i]){
            st.pop();
            count++;
        }
        if(!st.empty()) see[i] = count+1;
        else see[i] = count;
        st.push(heights[i]);
    }
    return see;
}
int main(){
    vector<int> heights = {10,6,8,5,11,9};
    int n = heights.size();
    vector<int> visible;
    visible = canSeePersonsCount(heights);
    for(int i = 0;i<n;i++){
        cout<<visible[i]<<" ";
    }
    return 0;
}