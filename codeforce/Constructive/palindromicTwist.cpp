// ascii difference must be 2
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t --){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int i = 0, j = n-1;
        bool flag = false;
        while(i < j){
            if(abs(s[i] - s[j]) == 2 || abs(s[i] - s[j]) == 0){
                flag = true;
            }
            else{
                flag = false;
                break;
            }
            i++;
            j--;
        }
        if(flag == true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}