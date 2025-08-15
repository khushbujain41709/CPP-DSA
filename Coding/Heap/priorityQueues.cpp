// Priority Queues are known as Heaps
// It is generally asked in Interviews
// If we want a data structure in which we can always get the minimum and maximum element at any point of time then we use priority queues.
// TC of fetching top = O(1)

// TC of insertion = O(logn) where n is current size
// If I insert n elements in a heap, 
// log 1 + log 2 + log 3 + log 4 + .. + log n = log(n!) = n*log(n)
// TC of deletion = O(logn) where n is current size

// To make a max Heap we use, #include<queue> and write priority_queue<int> pq;
// To make a min Heap we use, #include<queue> and write priority_queue<int, vector<int>, greater<int>> pq;

// How to identify?
// 1) Kth smallest, largest elements, top k frequent elements, closet k element.
// 2) At any point of time, minimum/maximum elements are required.
// 3) In heap sort
#include<iostream>
#include<queue>
using namespace std;
int main(){
    // maxHeap
    priority_queue<int> pq;  // c++ makes Max Heap by default
    pq.push(10);
    pq.push(-2);
    pq.push(46);
    pq.push(81);
    pq.push(6);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    // minHeap
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<float, vector<float>, greater<float>> pq3;
    pq2.push(10);
    pq2.push(-2);
    pq2.push(46);
    pq2.push(81);
    pq2.push(6);
    cout<<pq2.top()<<endl;
    pq2.pop();
    cout<<pq2.top()<<endl;
    return 0;
}