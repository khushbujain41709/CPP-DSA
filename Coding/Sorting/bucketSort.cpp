#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<float>& v){
    int n = v.size();
    for(int i = 0;i<n;i++){
        int j = i;
        while(j >= 1 && v[j] < v[j-1]){
            swap(v[j], v[j-1]);
            j--;
        }
    }
}
void bucketSort(vector<float>& v){
    int n = v.size();
    float maxx = FLT_MIN;
    for(int i = 0;i<n;i++){
        maxx = max(maxx , v[i]);
    }
    vector<vector<float>> bucket(n);
    for(int i = 0;i<n;i++){
        int bucketIndex = (v[i]*n)/(maxx+1);
        bucket[bucketIndex].push_back(v[i]);
    }
    for(int i = 0;i<n;i++){
        insertionSort(bucket[i]);
    }
    int k = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<bucket[i].size();j++){
            v[k++] = bucket[i][j];
        }
    }
}
int main(){
    vector<float> v = {0.4,6.2,1.3,8.0,1.1};
    bucketSort(v);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}