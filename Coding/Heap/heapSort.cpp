// Heap sort 
// TC = O(nlogn)
// Heapify Algorithm - Convert given array into heap
// Total leaf node of Complete BT having n nodes is n/2(if n is even) or n/2 + 1(if n is odd)
// Leaf nodes are heaps of size 1
#include<iostream>
using namespace std;
void heapify(int i, int arr[], int n){
    while(true){
        int left = 2*i;
        int right = 2*i + 1;
        if(left >= n){
            break;
        }
        if(right >= n){
            // we can still swap with left even if right goes out of bound because we have already checekd left condition above.
            if(arr[i] > arr[left]){
                swap(arr[i] , arr[left]);
                i = left;
            }
            break;
        }
        if(arr[left] < arr[right]){
            if(arr[i] > arr[left]){
                swap(arr[i] , arr[left]);
                i = left;
            }
            else{
                break;
            }
        }
        else{
            if(arr[i] > arr[right]){
                swap(arr[i] , arr[right]);
                i = right;
            }
            else{
                break;
            }
        }
    }
}
void print(int arr[], int n){
    for(int i = 0;i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {-1,10,3,4,2,8,9,1};  // -1 for index 0, ignore it
    int n = sizeof(arr)/4;
    print(arr, n);
    for(int i = n/2; i>= 1;i--){
        heapify(i, arr, n);
    }
    print(arr, n);
    return 0;
}