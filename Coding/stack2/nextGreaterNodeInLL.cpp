// Leetcode 1019
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class ListNode{
    public :
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};
vector<int> nextLargerNodes(ListNode* head) {
    stack<ListNode*> st;
    ListNode* temp = head;
    vector<int> output;
    while(temp != NULL){
        while(!st.empty() && (st.top())-> val < temp-> val){
            ListNode* change = st.top();
            st.pop();
            change ->val = temp-> val;  // 1 ko 5 mei change krdo then 2 ko 5 mei change krdo
        }
        st.push(temp);
        temp = temp -> next;
    }
    while(!st.empty()){  // 5 ko 0 mei cahnge krdo
        ListNode* change = st.top();
        st.pop();
        change ->val = 0;
    }
    while(head != NULL){
        output.push_back(head->val);
        head = head->  next;
    }
    return output;
}
int main(){
    
    return 0;
}