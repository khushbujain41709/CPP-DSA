#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    while(t --){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        int sum = 1 + n;
        vector<int> res(n);
        for(int i = 0; i<n; i++){
            res[i] = sum - a[i];
        }
        for(int i = 0; i<n; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}