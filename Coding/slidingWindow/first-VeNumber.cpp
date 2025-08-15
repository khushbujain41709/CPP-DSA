// First Negative Number in every window of size k
// TC = O(n)
// If no negative number is found in any window then simply print 1
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {12,1,3,-4,-1,2,1,-5,4};  
    // size = 9 and if k = 3 then n - k + 1 = 7 is elements in ans array
    int n = v.size();
    int k = 3;
    int p = -1;
    vector<int> ans(n-k+1);
    for(int i = 0;i<k;i++){
        if(v[i] < 0){
            p = i;
            break;
        }
    }
    if(p == -1) ans[0] = 1;
    else ans[0] = v[p];
    int i = 1;
    int j = k;
    while(j < n){
        if(p >= i) ans[i] = v[p];
        else{
            p = -1;
            for(int x = i; x <= j; x++){
                if(v[x] < 0){
                    p = x;
                    break;
                }
            }
            if(p != -1) ans[i] = v[p];
            else ans[i] = 1;
        }
        i++;
        j++;
    }
    for(int i = 0;i<n-k+1;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}