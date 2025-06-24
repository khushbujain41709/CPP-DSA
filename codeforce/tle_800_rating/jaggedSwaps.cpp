#include<bits/stdc++.h>
using namespace std;
bool isSorted(vector<int>& v){
    int n = v.size();
    vector<int> v1;
    for(int i = 0;i<n;i++){
        v1.push_back(v[i]);
    }
    sort(v1.begin(), v1.end());
    for(int i = 0;i<n;i++){
        if(v1[i] != v[i]) return false;
    }
    return true;
}
int main(){
    int tasty;
    cin>>tasty;
    while(tasty --){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i< n;i++){
            cin>>a[i];
        }
        if(isSorted(a)){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            bool flag = true;
            while(flag){
                // flag ko false krdo
                flag = false;
                for(int i = 1; i< n-1 ; i++){
                    if(a[i] > a[i-1] && a[i] > a[i+1]){
                        swap(a[i], a[i+1]);
                        flag = true;
                        // agar swaps nahi hue toh false hee rhega flag;
                    }
                }
            }
        }
        if(isSorted(a))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
