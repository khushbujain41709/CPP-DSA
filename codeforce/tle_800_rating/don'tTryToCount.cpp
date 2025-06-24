#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t --){
        int n,m;
        cin>>n>>m;
        string x, s;
        cin>>x>>s;
        // 1 - 2 - 4 - 8 - 16 - 32 length 
        // in worst case n = 1 and m = 25
        string x0 = x;
        string x1 = x0 + x0; // operation 1
        string x2 = x1 + x1; // operation 2
        string x3 = x2 + x2; // operation 3
        string x4 = x3 + x3; // operation 4
        string x5 = x4 + x4; // operation 5
        if(x0.find(s) != string::npos){
            cout<<0<<endl;
        }
        else if(x1.find(s) != string::npos){
            cout<<1<<endl;
        }
        else if(x2.find(s) != string::npos){
            cout<<2<<endl;
        }
        else if(x3.find(s) != string::npos){
            cout<<3<<endl;
        }
        else if(x4.find(s) != string::npos){
            cout<<4<<endl;
        }
        else if(x5.find(s) != string::npos){
            cout<<5<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}