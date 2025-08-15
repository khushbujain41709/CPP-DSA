#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    int minn = INT_MAX;
    for(int i = 0; i<n; i++){
        minn = min(abs(a[i]), minn);
    }
    cout<<minn;
    return 0;
}