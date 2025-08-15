// Follows FIFO property.
// Pops elements from front and pushes from rear
// Overflow happens only if we implement the queue using an array or when we are out of memory.
// Underflow - Whenever the queue is empty and we try to use these functions - pop(), front(), back()
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int>& q){
    int n = q.size();
    for(int i = 0 ;i<n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
}
void reverse(queue<int>& q){
    int n = q.size();
    stack<int> st;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        st.push(x);
    }
    while(!st.empty()){
        int x = st.top();
        st.pop();
        q.push(x);
    }
}
void removeEvenIndexElements(queue<int>& q){
    int n = q.size();
    for(int i = 0;i<n;i++){
        if(i%2 == 0){
            q.pop();
        }
        else{
            int x = q.front();
            q.pop();
            q.push(x);

        }
    }
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    display(q);
    q.pop();
    cout<<endl;
    display(q);
    cout<<endl;
    reverse(q);
    display(q);
    cout<<endl;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    cout<<endl;
    removeEvenIndexElements(q);
    display(q);
    return 0;
}