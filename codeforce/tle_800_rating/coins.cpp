#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    while(t --){
        long long n,k;
        cin>>n>>k; 
        if(n % 2 == 0 || (n-k) % 2 == 0){  // modulo operator has more priority than subtraction operator
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}