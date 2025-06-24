// If parent is at i, then left child is at 2*i and right child is at 2*i + 1
// If child is at i, then the parent is always at i/2, only if 1 based indexing is used
#include<iostream>
// MaxHeap implementation using Array
// If we want maximum element, we directly return arr[1]
// If maxHeap is of size 100 then arr is of size 101 and arr[0] is not used at all.
// Priority queue is starts from index 1 to idx-1.
using namespace std;
class MinHeap{
    public:
    int *arr;
    int idx;
    MinHeap(int size){
        arr = new int[size];
        idx = 1;
    }
    int top(){
        return arr[1];
    }
    void push(int val){
        arr[idx] = val;
        int i = idx;
        idx++;
        while(i != 1 && arr[i] > arr[i/2]){
            swap(arr[i] , arr[i/2]);
            i = i/2;
        }
    }
    void pop(){
        idx --;
        arr[1] = arr[idx];
        int i  = 1;
        while(true){
            int left = 2*i;
            int right = 2*i + 1;
            if(left > idx - 1){
                break;
            }
            if(right > idx - 1){
                // we can still swap with left even if right goes out of bound because we have already checekd left condition above.
                if(arr[i] > arr[left]){
                    swap(arr[i] , arr[left]);
                    i = left;
                }
                break;
            }
            if(arr[left] > arr[right]){
                if(arr[i] < arr[left]){
                    swap(arr[i] , arr[left]);
                    i = left;
                }
                else{
                    break;
                }
            }
            else{
                if(arr[i] < arr[right]){
                    swap(arr[i] , arr[right]);
                    i = right;
                }
                else{
                    break;
                }
            }
        }
    }
    int size(){
        return idx-1;
    }
    void display(){
        for(int i = 1; i<= idx - 1; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MinHeap* pq = new MinHeap(4);
    pq->push(10);
    pq->push(20);
    pq->push(11);
    pq->push(30);
    pq->pop();
    cout<<pq->top()<<endl;
    pq->display();
    pq->push(40);
    pq->push(12);
    cout<<pq->top()<<endl;
    pq->display();
    pq->push(4);
    pq->push(7);
    cout<<pq->top()<<endl;
    pq->display();
    return 0;
}