#include<iostream>
#include<queue>
using namespace std;
// method 1 - BuiltIn sort, hence return arr[k-1], TC = O(nlogn) and SC = O(logn)
// method 2 - Selection sort as it places smallest elements in every iteration in it's correct place, TC = O(k*n) and SC = O(n)
// method 3 - Quick select, TC = O(n) not in the worst case
// method 4 - Using Heap, TC = O(n*log k)
int main(){
    // If we need to find Kth smallest element, use maxHeap
    // If we need to find Kth largest element, use minHeap
    // This is because, if we use minHeap to find kth smallest element then TC will be n*log(n) for inserting all elements in heap + k*log(n) and popping k-1 smallest elements.
    
    return 0;
}