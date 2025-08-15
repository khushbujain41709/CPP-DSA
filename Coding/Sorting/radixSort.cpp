#include<bits/stdc++.h>
using namespace std;
int getMax(vector<int>& v){
    int maxx = INT_MIN;
    for(int i = 0;i<v.size();i++){
        maxx = max(maxx, v[i]);
    }
    return maxx;
}
void countSort(vector<int>& v, int digit){
    int n = v.size();
    vector<int> output(n);
    vector<int> count(10,0);
    for(int i = 0;i<n;i++){
        count[(v[i] / digit) % 10] ++;
    }
    for(int i = 1;i<10;i++){
        count[i] = count[i] + count[i-1];
    }
    for(int i = n - 1;i >= 0;i--){
        output[count[(v[i]/ digit)%10] - 1] = v[i];
        count[(v[i]/digit)%10] = count[(v[i]/digit)%10] - 1;
    }
    for(int i = 0;i<n;i++){
        v[i] = output[i];
    }
}
void radixSort(vector<int>& v){
    int maxx = getMax(v);
    for(int i = 1; maxx/i > 0; i *= 10){ // i is number of digits in maximum number.
        countSort(v,i);
    }
}
int main(){
    vector<int> v = {2,3432,22,6,8,3,22,123};
    int n = v.size();
    radixSort(v);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}