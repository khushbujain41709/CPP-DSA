/*
int sum = a[n-1];       // sum = a[3] = 1
int maxx = a[n-1] - 1;  // maxx = 1 - 1 = 0

Now, loop from i = n-2 to 0 (i.e., i = 2, 1, 0):
i = 2:
sum += min(maxx, a[2]) = min(0, 1) = 0  // sum = 1 + 0 = 1
maxx = min(0, 1) - 1 = 0 - 1 = -1
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i = 0; i< n; i++){
        cin>>a[i];
    }
    long long sum = a[n-1];
    long long maxx = a[n-1] -1;
    for(int i = n-2; i>= 0; i--){
        sum += min(maxx, a[i]);
        maxx = min(maxx, a[i]) - 1;
        if(maxx <= 0) break; // <= is imp as == is wrong for case 1 1 1 1
    }
    cout<<sum;
    return 0;
}