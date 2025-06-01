// Leetcode 232
#include<iostream>
#include<stack>
using namespace std;
// push efficient method
class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {

    }
    void push(int x) { // O(1)
        st.push(x);
    }
    int pop() { // O(n) 
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        helper.pop();
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    int peek() { // O(n)
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    bool empty() {
        if(st.size() == 0) return true;
        else return false;
    }
};

// pop and peek efficient method
class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {

    }
    void pushAtBottom(int x){
        while(!st.empty()){
            helper.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!helper.empty()){
            st.push(helper.top());
            helper.pop();
        }
    }
    void push(int x) { // O(n)
        pushAtBottom(x);
    }
    int pop() { // O(1) 
        int x = st.top();
        st.pop();
        return x;
    }
    int peek() { // O(1)
        int x = st.top();
        return x;
    }  
    bool empty() {
        if(st.size() == 0) return true;
        else return false;
    }
};

int main(){
    
    return 0;
}