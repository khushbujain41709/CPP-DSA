#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<float>& v){
    int n = v.size();
    for(int i = 0;i<n-1;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        swap(v[minIndex] , v[i]);
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
        selectionSort(bucket[i]);
    }
    int k = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<bucket[i].size();j++){
            v[k++] = bucket[i][j];
        }
    }
}

void bubbleSort(vector<float>& v){
    int n = v.size();
    for(int i = 0;i<n-1;i++){
        bool flag = true;
        for(int j = 0;j<n-i-1;j++){
            if(v[j] > v[j + 1]){
                swap(v[j] , v[j+1]);
                flag = false;
            }
        }
        if(flag == true) break;
    }
}

void merge(vector<int>& a , vector<int>& b, vector<int>& res){
    int m = a.size();
    int n = b.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < m && j < n){
        if(a[i] <= b[j]){
            res[k] = a[i];
            i++;
            k++;
        }
        else{
            res[k] = b[j];
            j++;
            k++;
        }
    }
    if( i == m){
        while(j < n){
            res[k] = b[j];
            j++;
            k++;
        }
    }
    else if(j == n){
        while( i < m){
            res[k] = a[i];
            i++;
            k++;
        }
    }
}
void mergeSort(vector<int>& v){
    int n = v.size();
    if( n == 1) return;
    int n1 = n/2;
    vector<int> a(n1);
    int n2 = n- n/2;
    vector<int> b(n2);
    for(int i = 0;i<n1;i++){
        a[i] = v[i];
    }
    for(int i = 0;i<n2;i++){
        b[i] = v[i + n1];
    }
    mergeSort(a);
    mergeSort(b);
    merge(a,b,v);
    a.clear();
    b.clear();
}
int partition(vector<int>& v, int low, int high){
    int pivot = v[high];
    int i = low - 1;
    for(int j = low ;j<high;j++){
        if(v[j] < pivot){
            i++;
            swap(v[i] , v[j]);
        }
    }
    swap(v[i+1] , v[high]);
    return i+1;
}
void quickSort(vector<int>& v,int low , int high){
    int n = v.size();
    if( low > high) return;
    int pivot = partition(v, low , high);
    quickSort(v,low , pivot-1);
    quickSort(v,pivot+1 , high);
}

int main(){
    vector<float> v = {0.4,6.2,1.3,8.0,1.1};
    bucketSort(v);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    vector<int> v1 = {35,2,46,20,47};
    mergeSort(v1);
    for(int i = 0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    vector<int> v2 = {35,2,46,20,47};
    quickSort(v2, 0 , v2.size() - 1);
    for(int i = 0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
}