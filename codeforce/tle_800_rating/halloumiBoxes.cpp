#include<bits/stdc++.h>
using namespace std;
bool isSorted(vector<int>& nums){
    int n = nums.size();
    vector<int> ans = nums;
    sort(nums.begin(), nums.end());
    if(nums == ans) return true;
    else return false;
}
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    while(t --){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        if(k == 1){
            if(!isSorted(a)){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
        else cout<<"YES"<<endl;
    }
}