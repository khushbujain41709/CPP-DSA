#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    unordered_set<int> khushbu;
    while(t --){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        unordered_map<int, int> m;
        for(int i = 0; i<n; i++){
            m[a[i]]++;
        }
        if(m.size() == 1){
            cout<<"Yes"<<endl;
            continue;
        }
        else if(m.size() == 2){
            int countDiff = 0;
            for(auto x: m){
                countDiff = x.second - countDiff;
            }
            countDiff = abs(countDiff);
            if(countDiff == 0 || countDiff == 1){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            cout<<"No"<<endl;
        }
    }
}