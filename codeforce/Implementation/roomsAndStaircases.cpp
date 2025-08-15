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
        string s;
        cin>>s;
        int maxx = n;
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                maxx = max(n+1, 2*(i+1));
            }
        }
        reverse(s.begin(), s.end());
        int maxx2 = n;
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                maxx2 = max(n+1, 2*(i+1));
            }
        }
        cout<<max(maxx, maxx2)<<endl;
    }
}