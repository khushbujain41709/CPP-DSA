// Leetcode 1475
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> ans(n, 0);
    stack<int> st;
    st.push(prices[n-1]);
    for(int i = n-2; i >= 0;i--){
        while(!st.empty() && st.top() > prices[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(prices[i]);
    }
    for(int i = 0 ; i<n; i++){
        if(ans[i] != -1){
            ans[i] = prices[i] - ans[i];
        }
        else{
            ans[i] = prices[i];
        }
    }
    return ans;
}
int main(){
    
    return 0;
}