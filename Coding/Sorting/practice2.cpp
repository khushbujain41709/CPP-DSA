#include<bits/stdc++.h>
using namespace std;
vector<int> countingSort(vector<int>& input){
    int n = input.size();
    vector<int> output(n);
    int maxx = INT_MIN;
    for(int i = 0;i<n;i++){
        maxx = max(maxx , input[i]);
    }
    vector<int> count(maxx +1 ,0);
    for(int i = 0;i<n;i++){
        count[input[i]]++;
    }
    for(int i = 1;i<count.size();i++){
        count[i] = count[i] + count[i -1];
    }
    for(int i = n-1;i>=0 ;i--){
        output[count[input[i]] - 1] = input[i];
        count[input[i]] = count[input[i]]  - 1;
    }
    return output;
}
int getMax(vector<int>& v){
    int maxx = INT_MIN;
    int n = v.size();
    for(int i = 0;i<n;i++){
        maxx = max(maxx , v[i]);
    }
    return maxx;
}
void countingRadix(vector<int>& v, int digit){
    int n = v.size();
    vector<int> count(10, 0);
    vector<int> output(n);
    for(int i = 0;i<n;i++){
        count[(v[i]/digit) % 10]++;
    }
    for(int i = 1;i<10;i++){
        count[i] = count[i] + count[i -1];
    }
    for(int i = n-1;i>=0 ;i--){
        output[count[(v[i]/digit) % 10] - 1] = v[i];
        count[(v[i]/digit) % 10] = count[(v[i]/digit) % 10]  - 1;
    }
    for(int i = 0;i<n;i++){
        v[i] = output[i];
    }
}
void radixSort(vector<int>& v){
    int n = v.size();
    int m = getMax(v);
    for(int i = 1; m/i > 0;i *= 10){
        countingRadix(v,i);
    }
}
int main(){
    vector<int> v1 = {35,2,46,20,47};
    vector<int> ans;
    ans = countingSort(v1);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    vector<int> v2 = {35,2,46,20,47};
    radixSort(v2);
    for(int i = 0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
}