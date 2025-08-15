// Leetcode 2326
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

int main(){
    
    return 0;
}