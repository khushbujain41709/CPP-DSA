// Leetcode 155
// You must implement a solution with O(1) time complexity for each function.
// method 1 : TC = O(n) and SC = O(n) for getMin(), use a helper stack and find minimum element and transfer all elements from stack st to helper then from helper to st again.
// method 2 : TC = O(1) and SC = O(n) for getMin() 
// method 3 : TC = O(n) and SC = O(1) for getMIn()
// method 4 : TC = O(1) and SC = O(1) for getMin()
#include<bits/stdc++.h>
using namespace std;
// Method 2
class MinStack {
    public:
    stack<int> st;
    stack<int> helper;
    MinStack() {
        
    }
    void push(int val) {
        st.push(val);
        if(helper.size() == 0 || val < helper.top()){
            helper.push(val);
        }
        else{
            helper.push(helper.top());
        }
    }
    void pop() {
        st.pop();
        helper.pop();
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return helper.top();
    }
};

// Method 3
class MinStack {
    public:
    stack<int> st;
    vector<int> v;
    MinStack() {
        
    }
    void push(int val) {
        v.push_back(val);
    } 
    void pop() {
        v.pop_back();
    }
    int top() {
        return v[v.size()-1];
    }
    int getMin() {
        int mini = v[0];
        for(int i = 0;i<v.size();i++){
            mini = min(mini , v[i]);
        }
        return mini;
    }
};

// method 4
class MinStack {
    public:
    // if val < min
    // val - min < 0
    // val + (val - min) < val equates to 2*val - min < val, this equation will give us smaller value then existing min and helps us to restore old min.
    stack<long long> st;
    long long minn;
    MinStack() {
        minn = LLONG_MAX;
    }
    void push(int val) {
        long long x = (long long) val;
        if(st.size() == 0){
            st.push(x);
            minn = x;
        } 
        else if(x >= minn){
            st.push(x);
        }
        else{ // val < min
            st.push(2*x - minn);
            minn = x;
        }
    }
    void pop() {
        if(st.top() < minn){ // A fake value is present
        // before popping make sure to retrieve the oldMin
            long long OldMin = 2*minn - st.top();
            minn = OldMin;
        }
        st.pop();
    }
    int top() {
        if(st.top() < minn) return (int)(minn);
        else return (int)st.top();
    }
    int getMin() {
        return (int)minn;
    }
};
int main(){

}