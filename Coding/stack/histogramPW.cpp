// Leetcode - 84 -> Largest Rectangle in Histogram
// Time Complexity - O(n)
// Space Complexity - O(n)
#include<iostream>
#include<stack>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int largestRectangleArea(vector<int> &v){
    int n = v.size();
    stack<int> st;
    vector<int> nsi(n), psi(n);
    // nsi
    nsi[n-1] = n;
    st.push(n-1);
    for(int i = n-2;i>=0;i--){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if(!st.empty()){
            nsi[i] = st.top();
        }
        else nsi[i] = n;
        st.push(i);
    }

    while(!st.empty()) st.pop(); // empty the old stack

    // psi
    psi[0] = -1;
    st.push(0);
    for(int i = 1;i<n;i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if(!st.empty()){
            psi[i] = st.top();
        }
        else psi[i] = -1;
        st.push(i);
    }
    vector<int> answer(n);
    int maxx = INT_MIN;
    for(int i = 0;i<n;i++){
        answer[i] = v[i] * (nsi[i] - psi[i] - 1); 
        // area = height * breadth
        // height = v[i]
        // breadth = nsi[i] - psi[i] - 1
        maxx = max(maxx, answer[i]);
    }
    return maxx;
}
int main(){
    vector<int> v;
    int num , answer;
    cout<<"Enter no. of elements : ";
    cin>>num;
    for(int i = 0;i<num;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    answer = largestRectangleArea(v);
    cout<<answer;
    return 0;
}