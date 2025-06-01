// Leetcode - 2487
// Remove nodes from Linked List
#include<iostream>
#include<stack>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};
ListNode* removeNodes(ListNode* head){
    stack<ListNode*> st;
    while(head){
        st.push(head);
        head = head->next;
    }
    ListNode* tail = st.top();
    st.pop();
    int maxx = tail->val;
    while(!st.empty()){
        ListNode* top = st.top();
        st.pop();
        if(top->val >= maxx){
            top->next = tail;
            tail = top;
            maxx = top->val;
        }
    }
    return tail;
}
int main(){
    return 0;
}