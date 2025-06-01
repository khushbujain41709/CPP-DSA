// Reorder Queue(Interleave 1st half with 2nd half)
// Do this by using one stack only
// Queue length is even always.
// Steps :
// 1) first half ko q se stack mei dalo then stack se q mei
// 2) second half ko stack mei dalo
// 3) now one by one, stack se q mei ek element dalo then q se q mei ek element dalo then again ye step repeat kro baki elements k liye.
// 4) reverse the queue for final answer
// TC = O(n) and SC = O(n)
#include<iostream>
#include<queue>
#include<Stack>
using namespace std;
void reorder(queue<int>& q){
    stack<int> st;
    int n = q.size()/2;
    // step 1
    for(int i = 0;i<n;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    // step 2
    for(int i = 0;i<n;i++){
        st.push(q.front());
        q.pop();
    }
    // step 3
    while(!st.empty()){
        q.push(st.top());
        st.pop();
        int x = q.front();
        q.pop();
        q.push(x);
    }
    // step 4
    while(!q.empty()){
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
    q.push(60);
    q.push(70);
    q.push(80);
    display(q);
    reorder(q);
    display(q);
    return 0;
}