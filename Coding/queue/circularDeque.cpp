// Leetcode 641
/*
 MyCircularDeque dq(5);
dq.insertLast(10);  // arr = [10, _, _, _, _], f=0, b=1
dq.insertLast(20);  // arr = [10, 20, _, _, _], f=0, b=2
dq.insertFront(5);  // arr = [10, 20, _, _, 5], f=4, b=2
dq.getFront();      // returns 5
dq.getRear();       // returns 20
dq.deleteFront();   // f = 0 now
dq.deleteLast();    // b = 1 now

 */
#include<iostream>
#include<vector>
using namespace std;
class MyCircularDeque {
public:
    int c;
    int f;
    int b;
    int s; // current size
    vector<int> arr;
    MyCircularDeque(int k) {
        c = k;
        s = 0;
        f = 0;
        b = 0;
        vector<int> v(k);
        arr = v;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        f = (f-1+c) % c; // move front backward 
        arr[f] = value; // see order of lines
        s++;
        return true; 
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        arr[b] = value; // see order of lines
        b = (b+1)%c;
        s++;
        return true; 
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        f = (f+1)%c;
        s--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        b = (b-1+c)%c;
        s--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        else return arr[f];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        else return arr[(b-1+c) % c];
    }
    
    bool isEmpty() {
        return (s == 0);
    }
    
    bool isFull() {
        return (s == c);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main(){
    
    return 0;
}