// Disadvantages over LinkedList :
// 1)wastage of memory or space
#include<iostream>
using namespace std;
class queue{
    public:
    int capacity;
    int* arr;
    int front;
    int back;
    queue(int val){
        capacity = val;
        arr = new int[val];
        front = 0;
        back = 0;
    }
    void push(int data){
        if(back == capacity){
            cout<<"Overflow"<<endl;
            return;
        }
        else{
            arr[back] = data;
            back++;
        }
    }
    int size(){
        return back-front;
        // In case queue is empty size = 0 as back = 0 and front = 0 so back-front = 0
    }
    void pop(){
        if(size() == 0){
            cout<<"Underflow"<<endl;
            return;
        }
        else{
            front++;
        }
    }
    void display(){
        for(int i = front;i<back;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int top(){
        if(size() == 0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return arr[front];
    }
    int backk(){
        if(size() == 0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return arr[back -1];
    }
    bool isEmpty(){
        if(size() == 0) return true;
        else return false;
    }
};
int main(){
    queue* q = new queue(5);
    q->push(10);
    q->push(20);
    q->push(30);
    q->push(40);
    q->push(50);
    q->display();
    cout<<q->size()<<endl;
    q->pop();
    q->display();
    cout<<q->size()<<endl;
    return 0;
}