#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// method 1 - BuiltIn sort, hence return arr[k-1], TC = O(nlogn) and SC = O(logn)
// method 2 - Selection sort as it places smallest elements in every iteration in it's correct place, TC = O(k*n) and SC = O(n)
// method 3 - Quick select, TC = O(n) not in the worst case
// method 4 - Using Heap, TC = O(n*log k)
int main(){
    // If we need to find Kth smallest element, use maxHeap
    // If we need to find Kth largest element, use minHeap
    // This is because, if we use minHeap to find kth smallest element then TC will be n*log(n) for inserting all elements in heap + k*log(n) and popping k-1 smallest elements.

    // Approach - We make a maxHeap of size k, traverse in array and the element at top after traversing the array is the kth smallest element
    // if size of the heap is full then pop the top element as k elements are in heap which are less than the top element.
    vector<int> v = {10,7,9,3,2,-1,6,-9,8};
    priority_queue<int> pq;
    int k = 3;
    for(int i = 0 ; i< v.size();i++){  // O(n)
        pq.push(v[i]);  // logk
        if(pq.size() > k) pq.pop();   // logk
    } 
    // So total TC = O(n*logk)
    // Total SC = O(n)
    // Total Auxillairy SC = O(k)
    cout<<pq.top()<<endl;
    return 0;
}