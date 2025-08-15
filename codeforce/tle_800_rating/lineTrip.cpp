#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    unordered_set<int> khushbu;
    while(t --){
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        int maxx = a[0];
        vector<int> diff;
        if(n == 1){
            maxx = a[0]; // a[0] - 0 is a startPoint
        }
        else{
            for(int i = 0; i<n-1; i++){
                diff.push_back(a[i+1] - a[i]);
            }
        }
        int endPoint = 2*(x - a[n-1]);
        for(int i = 0; i< diff.size(); i++){
            maxx = max(maxx, diff[i]);
        }
        maxx = max(maxx, endPoint);
        cout<<maxx<<endl;
    }
}