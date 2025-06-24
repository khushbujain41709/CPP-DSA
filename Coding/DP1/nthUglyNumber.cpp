// Leetcode 264
// O(n) time with O(n) space
// dry run for n = 10 and see
#include<iostream>
#include<vector>
using namespace std;
int nthUglyNumber(int n) {
    if(n == 1) return 1;
    vector<int> dp(n);
    dp[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for(int i = 1;i<n;i++){
        int next2 = dp[i2] * 2;
        int next3 = dp[i3] * 3;
        int next5 = dp[i5] * 5;
        int next = min(next2, min(next3, next5));
        dp[i] = next;
        if(next == next2) i2++;  // if is used as 2*3 and 3*3 is 6 so we need to increment both i2 and i3
        if(next == next3) i3++;
        if(next == next5) i5++;
    }
    return dp[n-1];
}
int main(){
    return 0;
}
