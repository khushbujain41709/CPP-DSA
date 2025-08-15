#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int rev = 1;
        int count = 0;
        vector<int> v;
        while(n > 0){
            int digit = n % 10;
            if(digit != 0){
                v.push_back(digit*rev);
                count++;
            } 
            rev = rev*10;
            n = n/10;
        }
        cout<<count<<endl;
        for(int i = 0; i<v.size(); i++){
            cout<<v[i]<< " ";
        }
        cout<<endl;
    }
    return 0;
}