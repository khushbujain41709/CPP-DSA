#include<bits/stdc++.h>
# define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    while(t --){
        ll n;
        cin>>n;
        vector<ll> a(n);
        // ll pro = 1;
        int twos = 0;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            if(a[i] == 2) twos++; 
            // pro *= a[i];  // Gives TLE as 2^ 1000 is out of long long range
        }
        // ll curr = 1;
        bool flag = false;
        int currTwo = 0;
        for(int i = 0; i<n; i++){
            if(a[i] == 2) currTwo++;
            if(twos - currTwo == currTwo){
                cout<<i+1<<endl;
                flag = true;
                break;
            }
        }
        if(flag == false) cout<<-1<<endl;
    }
}