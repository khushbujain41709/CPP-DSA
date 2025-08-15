#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    // map<int, int> m;  Don't use map as it doesnot allow duplicate entries
    vector<pair<int, int>> m;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        pair<int, int> p = {a[i], i+1}; // sort according to a[i]
        m.push_back(p);
    }
    sort(m.begin(), m.end());
    vector<int> v;
    int sum = 0;
    for(auto x : m){
        if(sum + x.first <= k){
            sum += x.first;
            v.push_back(x.second);
        }
    }
    cout<<v.size()<<endl;
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}