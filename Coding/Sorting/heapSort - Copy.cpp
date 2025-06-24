#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& v , int n , int i){
    int largest = i;
    int l = 2* i + 1;
    int r = 2* i + 2;
    if(l < n && v[l] > v[largest]) largest = l;
    if(r < n && v[r] > v[largest]) largest = r;
    if(largest != i){
        swap(v[i] , v[largest]);
        heapify(v, n , largest);
    }
}
void heapSort(vector<int>& v){
    int n = v.size();
    for(int i = n/2 - 1;i>= 0;i--){
        heapify(v, n,i);
    }
    for(int i = n - 1;i> 0;i--){
        swap(v[i] , v[0]);
        heapify(v, i , 0);
    }
}
int main(){
    vector<int> v2 = {35,2,46,20,47};
    heapSort(v2);
    for(int i = 0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
}