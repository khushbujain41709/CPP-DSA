// Leetcode - 622
#include<iostream>
#include<vector>
using namespace std;
class MyCircularQueue {
public:
    int s; // current size
    int f;
    int b;
    int c; // capacity // imp
    vector<int> arr;
    MyCircularQueue(int k){
        s = 0;
        f = 0;
        b = 0;
        c = k;
        vector<int> v(k);
        arr = v;
    }
    
    bool enQueue(int value) {
        if(s == c) return false;
        else{
            arr[b] = value;
            b++;
            if(c == b) b = 0; // IMP
            s++;
            return true;
        }
    }
    
    bool deQueue() {
        if(s == 0) return false;
        f++;
        if(f == c) f = 0; // IMP
        s--;
        return true;
    }
    
    int Front() {
        if(s == 0) return -1;
        else return arr[f];
    }
    
    int Rear() {
        if(s == 0) return -1;
        if(b == 0) return arr[c-1]; // when f == b // IMP
        else return arr[b-1];
    }
    
    bool isEmpty() {
        if(s == 0) return true;
        else return false;
    }
    
    bool isFull() {
        if(s == c) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
int main(){
    
    return 0;
}