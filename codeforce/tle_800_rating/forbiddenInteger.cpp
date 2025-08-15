#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    while(t --){
        int n,k,x;
        cin>>n>>k>>x;
        if(x != 1){
            cout<<"YES"<<endl;
            cout<<n<<endl;
            for(int i = 0; i<n; i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }
        else{ // x == 1
            if(k == 1){
                cout<<"NO"<<endl;
            }
            else if(n % 2 != 0 && k == 2){
                cout<<"NO"<<endl;
            }
            else if (n % 2 == 0){
                // If n is even, we can always use 2s
                cout<<"YES"<<endl;
                cout<< n/2 <<endl;
                for(int i = 0; i < n / 2; i++){
                    cout<<2<<" ";
                }
                cout<<endl;
            }
            else if(k >= 3){  // n is odd
                // Use one 3, rest with 2s
                cout<<"YES"<<endl;
                cout << (n - 3) / 2 + 1 <<endl;
                cout<<3<<" ";
                for(int i = 0; i < (n - 3) / 2; ++i){
                    cout<<2<<" ";
                }
                cout<<endl;
            }  
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}