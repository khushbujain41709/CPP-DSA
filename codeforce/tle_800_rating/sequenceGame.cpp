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
        vector<int> b(n), a;
        for(int i = 0; i<n; i++){
            cin>>b[i];
        }
        a.push_back(b[0]);
        for(int i = 1; i<n; i++){
            if(b[i] < b[i-1]){
                if(b[i]-1 == 0){
                    a.push_back(1);
                }
                else a.push_back(b[i]-1);
            }
            a.push_back(b[i]);
        }
        cout<<a.size()<<endl;
        for(int i = 0; i<a.size(); i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}