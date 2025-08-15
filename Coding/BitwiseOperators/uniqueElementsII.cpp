// Leetcode 260 single Number III
// In an array, Every element occurs twice times excpet two element. Return both elements.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v = {1,2,1,3,2,5};
    int k = 0;
    int res = 0;
    int n = v.size();
    for(int i = 0;i<n;i++){
        res = res ^ v[i];
    } // res = 3 ^ 5 = 6
    int temp = res;
    while(true){
        if((temp & 1) == 1) break; // checks if bit is 1 or not 
        temp = temp >> 1;  // 1101 -> 0110
        k++;
    } // res = 6 = 0110, so k = 1
    // Divide elements into two groups based on bit k
    int res2 = 0;
    for(int i = 0;i<n;i++){
        int num = v[i];
        if(((num >> k) & 1) == 1) res2 = res2 ^ num; 
        // Group 1 (bit at k = 1): XOR in res2
        /*
        Iteration 1:
        temp = 6 → 0110
        (temp & 1) = (0110 & 0001) = 0 → not set → shift right
        temp >> 1 = 3 → 0011
        k++ → k = 1
        Iteration 2:
        temp = 3 → 0011
        (temp & 1) = (0011 & 0001) = 1 → set → break!
        */
    }
    /*
    1 = 0001 → bit1=0 → skip
    2 = 0010 → bit1=1 → XOR
    1 = 0001 → skip
    3 = 0011 → bit1=1 → XOR
    2 = 0010 → bit1=1 → XOR
    5 = 0101 → bit1=0 → skip
    */
    // res2 = 2 ^ 3 ^ 2 = 3
    vector<int> ans(2);
    v.push_back(res2);
    res = res2 ^ res; // res = 6 ^ 3 = 5
    v.push_back(res);
    cout<<res2<<" "<<res<<endl;
    return 0;
}