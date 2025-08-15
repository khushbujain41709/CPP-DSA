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
        int maxx = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(a[i] == 0){
                count++;
                maxx = max(maxx, count);
            }
            else count = 0;
        }
        cout<<maxx<<endl;
    }
}