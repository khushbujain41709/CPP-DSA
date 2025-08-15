// It is implemented using doubly linked list
// We can do push and pop from both sides that is from front we can do both push and pop and from back we can do both push and pop.
#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(46);
    dq.push_back(60);
    dq.push_front(47);
    dq.push_front(50);
    dq.pop_back();
    dq.pop_front();
    return 0;
}