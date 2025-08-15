#include<bits/stdc++.h>
using namespace std;
// arrange in this manner - maxx minn remaining elements
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    while(t --){
        int n;
        cin>>n;
        vector<int> a(n);
        int maxx = INT_MIN;
        int minn = INT_MAX;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            maxx = max(maxx, a[i]);
            minn = min(minn, a[i]);
        }
        if(n == 2 && a[0] == a[1]){
            cout<<"NO"<<endl;
            continue;
        }
        if(maxx == minn){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            sort(a.begin(), a.end());
            cout<<"YES"<<endl;
            cout<<maxx<<endl;
            for(int i = 0; i<n-1; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
}