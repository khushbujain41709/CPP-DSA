// Advantages over array :
// 1) Unlimited Size
// 2) No wastage of memory or space
// 3) If fixed size is given then use circular array
// Disadvantges over array:
// 1) Each node carries two data that is value and next pointer
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class Queue{
    public:
    Node* head;
    Node* tail;
    int size;
    Queue(){
        this->size = 0;
        head = NULL;
        tail = NULL;
    }
    void push(int val){ // insertAtTail == push
        Node* temp = new Node(val);
        if(size == 0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void pop(){ // deleteAtHead
        if(size == 0){
            cout<<"Underflow"<<endl;
            return;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete(temp);
        }
        size--;
    }
    int front(){
        if(size == 0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(size == 0){
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
    int sizze(){
        return size;
    }
    bool isEmpty(){
        if(size == 0) return true;
        else return false;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    cout<<q.sizze()<<endl;
    q.pop();
    q.display();
    cout<<q.sizze()<<endl;
    return 0;
}