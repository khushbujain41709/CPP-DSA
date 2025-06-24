// Reverse First K Elements
// do not while loop in this question
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverseFirstK(queue<int>& q , int k){
    stack<int> st;
    for(int i = 0;i<k;i++){
        int x = q.front();
        q.pop();
        st.push(x);
    }
    while(!st.empty()){
        int x = st.top();
        st.pop();
        q.push(x);
    }
    int n = q.size();
    int rem = n-k;
    for(int i = 0;i<n-k;i++){
        int x = q.front();
        q.pop();
        q.push(x);
        
    }
}
void reverseLastK(queue<int>& q , int k){
    int n = q.size();
    stack<int> st;
    int o = n-k;
    for(int i = 0;i<o;i++){
        q.push(q.front());
        q.pop();
    }
    for(int i = 0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}
void display(queue<int>& q){
    int n = q.size();
    for(int i = 0 ;i<n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    reverseLastK(q,3);
    display(q);
    return 0;
}