#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class Deque{
    public:
    int sizze;
    Node* head;
    Node* tail;
    Deque(){
        head = tail = NULL;
        sizze = 0;
    }
    void push_front(int val){
        Node* temp = new Node(val);
        if(sizze == 0){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        sizze++;
    }
    void push_back(int val){
        Node* temp = new Node(val);
        if(sizze == 0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        sizze++;
    }
    void pop_front(){
        if(sizze == 0){
            cout<<"Queue is Empty : Underflow"<<endl;
            return;
        }
        head = head->next;
        if(head) head->prev = NULL;
        if(head == NULL) tail = NULL;
        sizze--;
    }
    void pop_back(){
        if(sizze == 0){
            cout<<"Queue is Empty : Underflow"<<endl;
            return;
        }
        // imp case
        else if(sizze == 1){
            pop_front();
            return;
        }
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        sizze--;
    }
    int front(){
        if(sizze == 0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(sizze == 0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return tail->val;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    int size(){
        return sizze;
    }
    bool isEmpty(){
        if(sizze == 0) return true;
        else return false;
    }
};
int main(){
    Deque dq;
    dq.push_back(46);
    dq.push_back(60);
    dq.push_front(47);
    dq.push_front(50);
    dq.pop_back();
    dq.pop_front();
    dq.display();
    return 0;
}