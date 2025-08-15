// Leetcode 61
#include<bits/stdc++.h>
using namespace std;
class ListNode{ // User defined data type
public:
    int value;
    ListNode* next;
    ListNode(int data ){
        value = data;
        next = NULL;
    }
};
class LinkedList{ // User defined data structure
public:
    ListNode* head;
    ListNode* tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insertAtEnd(int val){
        ListNode* new_node = new ListNode(val);
        if (head == NULL){   //Linked list is empty
            head = new_node;
            return;
        }
        ListNode* temp = head;
        while(temp ->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    void display(){ // since no changes is done to my linked list
        ListNode* temp = head;
        while(temp != NULL){
            cout<<temp->value<<"->";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    } 
};
// Method 1
ListNode* rotateRight(ListNode* head, int k){
    int count = 0;
    if(head == NULL || head-> next == NULL) return head;
    if(k == 0) return head;
    ListNode* temp = head;
    ListNode* tail = NULL;  // to mark tail
    while(temp != NULL){
        if(temp->next == NULL) tail = temp;
        count++;
        temp = temp->next;
        // tail = temp; wrong line to find tail 
    }
    if(k >= count) k = k % count; // imp
    // Reset temp
    temp = head;
    for(int i = 1; i<count-k; i++){
        temp = temp->next;
    }
    tail->next = head;
    head = temp->next;
    temp->next = NULL;
    return head;
}
// Method 2 - but doesnot give correct answer in leetcode
// Use slow and fast pointers
// slow = fast = head
// move fast k steps ahead
// move slow and fast together till fast->next == NULL
// fast->next = head;
// head = slow->next;
// slow->next = NULL;
int main(){
    
    return 0;
}