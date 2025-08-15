// To do - make find(x) , remove(x) in minHeap and maxHeap using Array implementation
// Leetcode 295
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
// gives TLE
class MedianFinder {
public:
    vector<int> v;
    MedianFinder() {
    }
    void addNum(int num) {
        v.push_back(num);
        sort(v.begin(), v.end());
    }
    double findMedian() {
        int n = v.size();
        if(n % 2 != 0){
            return v[n/2];
        }
        else{
            int num1 = v[n/2];
            int num2 = v[n/2 -1];
            return(( (float)num1 + num2) / 2);
        }
    }
};
// also gives TLE
class MedianFinder {
public:
    vector<int> v;
    MedianFinder() {
    }
    void addNum(int num) {
        v.push_back(num);
        int i = v.size()-1;
        while(i >= 1 && v[i] < v[i-1]){  // insertion sort - only insert last element at it's correct place instead of sorting whole array
            swap(v[i] , v[i-1]);
            i--;
        }
    }
    double findMedian() {
        int n = v.size();
        if(n % 2 != 0){
            return v[n/2];
        }
        else{
            int num1 = v[n/2];
            int num2 = v[n/2 -1];
            return(( (float)num1 + num2) / 2);
        }
    }
};
// correct approach
// make two heaps, one minHeap and one maxHeap
// all elements of left <= all elements of right
// size of left and right heap should be same or diffrence should be one
// if size is equal then median is avg of top of both the heaps
// if size is unequal then median is top of heap having more elements
class MedianFinder {
public:
    priority_queue<int> left;  // maxHeap // left mei sab chote elements honge
    priority_queue<int, vector<int> , greater<int>> right;  // minHeap // right mei sab bade elements honge
    MedianFinder() {
    }
    void addNum(int num) {  // O(log n)
        if(left.size() == 0 || num < left.top()){  // hamesha start left se krna hai
            left.push(num);
        }
        else{
            right.push(num);
        }
        if(left.size() > right.size() + 1){  // difference can be one but not more than one
            right.push(left.top());
            left.pop();
        }
        if(right.size() > left.size() + 1){  // difference can be one but not more than one
            left.push(right.top());
            right.pop();
        }
    }
    double findMedian() {  // O(1)
        if(left.size() == right.size()){
            return (left.top() + right.top())/ 2.0;
        }
        else{
            if(left.size() > right.size()){
                return left.top();
            }
            else{
                return right.top();
            }
        }
    }
};
int main(){
    
    return 0;
}